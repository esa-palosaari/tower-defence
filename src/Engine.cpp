#include "Engine.hpp"
#include "UserGraphics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>

// Starts the engine, loads the game map from file, starts the clock and calls UserGraphics
void Engine::StartEngine(){
    loadMap(10);
    clock.restart();
	  if(Level == 0){
      money += 1250;
	  }

    UserGraphics graph(this);
    graph.StartUserGraphics();
}
// Updates the engine every

// Checks if all enemies are dead
bool Engine::isAllDead(){
    if(enemies.size() < 1){
        return false;
    }
    for(int i = 0; i < enemies.size(); i++){
        if(!enemies[i].CheckDead()){
            return false;
        }
    }
    return true;
}
// Ends the game and saves top scores to .txt
void Engine::EndGame(){
  if(!GameEnd){
  	showTopScoreClk.restart();
  	std::ofstream out;
  	out.open("../src/maps/scores.txt",std::ios::app);
  	time_t now = time(0);
  	out << GameTag << ";" << score << ';';
    GameEnd = true;
  	out.close();

  	std::string line;
  	std::ifstream myfile("../src/maps/scores.txt");

  	if(myfile.is_open()){
  		int i = 1;
  		Scores temp;
  		while(getline(myfile, line, ';')){
  			switch(i){
  				case 1:
  					temp.name=line;
  					break;
  				case 2:
  					temp.score=stoi(line);
  					break;
  			}
  			i++;
  			if(i > 2){
  				i = 1;
  				HighScoresVec.push_back(temp);
  				Scores temp;
  			}
  		}

  		myfile.close();
  		std::sort(HighScoresVec.begin(), HighScoresVec.end());
  	}

  	else {
  		std::cout << "Unable to open file";
  	}
  }
}
// Check if level has been cleared,
// Raises level and resets the time
void Engine::CheckTimeOut(){
    if(isAllDead() && !TimeOut){
        TimeOut = true;
        TimeOutClock.restart();
    }
    if(TimeOutClock.getElapsedTime().asSeconds() > TimeOutTime && TimeOut){
        FileLoaded = false;
        enemies.clear();
        LevelUp();
        TimeOut = false;
        TimeOutTime = 10;
    }
}
// Spawns new enemies
void Engine::spawnEnemies(Types::NPC type){
	float LevelModifier = pow(1.08, Level);
  Enemy&& temp = Enemy(type, SpawnNumber, 0, 0, LevelModifier);
	if(type == Types::NPC::Aircraft){
		temp.InitializeSprite(0.f, 900.f);
	}
	else {
		temp.InitializeSprite(0.f, 160.f);
	}
    enemies.push_back(temp);
    SpawnNumber++;
}
void Engine::spawnEnemies(Types::NPC type, float x, float y, int muuttuja, float distance){
	float LevelModifier = pow(1.08, Level);
  Enemy&& temp = Enemy(type, SpawnNumber, muuttuja, distance, LevelModifier);
	if(type == Types::NPC::Aircraft){
		temp.InitializeSprite(0.f, 900.f);
	}
	else{
		temp.InitializeSprite(0.f, 160.f);
	}
    enemies.push_back(temp);
    SpawnNumber++;
}
// Spawns new towers
void Engine::spawnTower(Types::NPC type, float x, float y){
    Tower&& temp = Tower(this, type, x, y);
    temp.InitializeSprite();
    towers.push_back(temp);
}
// Loads the map from .txt - file into array
void Engine::loadMap(int id){

	std::string mapPath = "../src/maps/Map"+std::to_string(id)+".txt";
	std::ifstream mapFile(mapPath);
	std::string value;
	int level[510];
	int y = 0;
	while(std::getline(mapFile,value,',')){
		level[y]=std::stoi(value);
		y++;
	}
	if(!map.load("../src/photos/tilesheet3.png", sf::Vector2u(64,64), level, 30, 17)){
		std::cout<<"MAP NOT LOADED!"<<std::endl;
		return;
	}
}
// Updates the player to a next level
void Engine::LevelUp(){
  SpawnNumber = 0;
	SpawnedSlows = 0;
	SpawnedMediums = 0;
	SpawnedFasts = 0;
	SpawnedCommanders = 0;
	SpawnedKillers = 0;
	SpawnedAircrafts = 0;
	if(Level < 4){
		MaxEnemies = BaseLevels[Level][0] + BaseLevels[Level][1] + BaseLevels[Level][2]+BaseLevels[Level][3];
	}
  else {
		MaxEnemies = Level * 2;
	}
  Level++;
	score=score+10;
  enemies.reserve(MaxEnemies);
}
void Engine::Update(sf::Time elapsedTime){
    if(Level == 0 || FileLoaded){
        CheckTimeOut();
    }
    else {
        for(auto& enemy:enemies){ // Goes through the enemies and decreases HP
            auto EnemyPlacement = enemy.enemy.getPosition();
            enemy.Move(enemy.getType(), EnemyPlacement, elapsedTime);
            if(enemy.enemy.getPosition().x >= 1984 && !enemy.CheckDead()){
                if(HP > 0){
                    switch(enemy.getType()){
                        case(Types::NPC::Slow):
                            HP--;
                            break;
                        case(Types::NPC::Medium):
                            HP--;
                            break;
                        case(Types::NPC::Fast):
                            HP--;
                            break;
                  			case(Types::NPC::Aircraft):
                  				HP--;
                  				break;
                  			case(Types::NPC::Commander):
                  				HP -= 3;
                  				break;
                  			case(Types::NPC::Killer):
                  				HP -= 5;
                  				break;
                    }
                }
                enemy.setDead();
            }
        }
        // If HP > 0, towers start shooting
        std::sort(enemies.rbegin(), enemies.rend());
        for(auto& enemy : enemies){
            for(auto& tower : towers){
                if(HP > 0){
                    tower.Shoot(enemy);
                }
            }
        }
        // Retarget the towers
        for(auto& tower : towers){
            tower.ReTarget();
        }
        // Shared pointer for tower's projectiles
        // Checks status and shoots if projectile exists
        // Otherwise erases the the iterator
        for(std::vector<std::shared_ptr<Projectile>>::iterator i = projectiles.begin(); i != projectiles.end();){
            if(!i->get()->isBlownUp()){
                i->get()->Move(elapsedTime, enemies);
                int Income = i->get()->HitTarget(enemies);
            		if(Income > 0){
            			float LevelModifierScore = pow(1.05, Level);
            			float LevelModifierMoney = pow(1.03, Level);
            			int ModifiedScore = (int)(LevelModifierScore * 1);
            			int ModifiedIncome = (int)(LevelModifierMoney * Income);
            			score += ModifiedScore;
            			money += ModifiedIncome;
            		}
                i++;
            }
            else {
                i = projectiles.erase(i);
            }
        }
        // Determine the game difficulty according to player's level
        // Spawns new enemies
        if(Level < 5){
        	if(clock.getElapsedTime().asMilliseconds() > Interval && SpawnedSlows < BaseLevels[Level-1][0]){
            spawnEnemies(Types::NPC::Slow);
            SpawnedSlows++;
            clock.restart();
        	}
        	if(clock.getElapsedTime().asMilliseconds() > Interval && SpawnedMediums < BaseLevels[Level-1][1]){
            spawnEnemies(Types::NPC::Medium);
            SpawnedMediums++;
            clock.restart();
        	}
        	if(clock.getElapsedTime().asMilliseconds() > Interval && SpawnedFasts < BaseLevels[Level-1][2]){
            spawnEnemies(Types::NPC::Fast);
            SpawnedFasts++;
            clock.restart();
        	}
      		if(clock.getElapsedTime().asMilliseconds() > Interval && SpawnedCommanders < BaseLevels[Level-1][3]){
      			spawnEnemies(Types::NPC::Commander);
      			SpawnedCommanders++;
      			clock.restart();
      		}
        }
        else {
          if(clock.getElapsedTime().asMilliseconds()>Interval && enemies.size() < MaxEnemies-1){
            int DetermineType = rand() % 4 + 1;
            switch(DetermineType){
              case 1:
                spawnEnemies(Types::NPC::Slow);
                break;
              case 2:
                spawnEnemies(Types::NPC::Medium);
                break;
              case 3:
                spawnEnemies(Types::NPC::Fast);
                break;
            	case 4:
            		spawnEnemies(Types::NPC::Aircraft);
            		break;
            }
              clock.restart();
            }
    	  if(clock.getElapsedTime().asMilliseconds()>Interval && enemies.size() == MaxEnemies - 1){
    			int DetermineType = rand() % 5 +1;
    			switch(DetermineType){
    				case 1:
    					spawnEnemies(Types::NPC::Commander);
    					break;
    				case 2:
    					spawnEnemies(Types::NPC::Commander);
    					break;
    				case 3:
    					spawnEnemies(Types::NPC::Commander);
    					break;
    				case 4:
    					spawnEnemies(Types::NPC::Commander);
    					break;
    				case 5:
    					spawnEnemies(Types::NPC::Killer);
    					break;
    			}
        }
      }
        if(enemies.size() == MaxEnemies && HP > 0){
            CheckTimeOut();
        }
    }
}
Engine::~Engine(){}
