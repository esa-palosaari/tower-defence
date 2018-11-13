#include "Engine.hpp"
#include "UserGraphics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

// Starts the engine, loads the game map from file, starts the clock and calls UserGraphics
void Engine::StartEngine(){
    loadMap(1);
    clock.restart();
    UserGraphics graph(this);
    graph.StartEngine();
}

void Engine::Update(sf::Time elapsedTime){
    if(Level == 0 || FileLoaded){
        CheckTimeout();
    }
    else {
        for(auto& enemy:enemies){
            auto EnemyPlacement = enemy.enemy.getPosition();
            enemy.move(EnemyPlacement, elapsedTime);
            if(enemy.enemy.getPosition().x >= 1984 && !enemy.CheckDead()){
                if(HP>0){
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
                    }
                }
                enemy.Die();
            }
        }

        std::sort(enemies.rbegin(), enemies.rend());

        for(auto& enemy : enemies){
            for(auto& tower : towers){
                if(HP>0){
                    tower.Shoot(enemy); //Tower
                }
            }
        }

        for(auto& tower : towers){
            tower.ReTarget();   //Tower
        }

        for(std::vector<std::shared_ptr<Projectile>>iterator i=projectiles.begin(); i != projectiles.end(); ){
            if(!i->get()->DoesntExist()){       // Projectile
                i->get()->move(elapsedTime, enemies);   // Projectile
                i++;
            }
            else{
                i=projectiles.Remove(i);    //Projectile
            }
        }
        if(Level<=3){
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
        }
        else{
            if(clock.getElapsedTime().asMilliseconds()>Interval && enemies.size() < MaxEnemies){
                int DetermineType = rand() % 3 + 1;
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
                }
                clock.restart();
            }
        }
        if(enemies.size() == MaxEnemies && HP > 0){
            CheckTimeOut();
        }
    }
}

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


// Ends the game
void Engine::EndGame(){
    if(!GameEnd){
        GameEnd = true;
    }
}


// Saves the game into a .txt - file
void Engine::saveGame(std::string targetPath){
    std::ofstream out;
    out.open(targetPath, std::ios:app);
    out << money << ';' << Level << ';' << HP << ';';
    std::ostringstream AstreamT;
    boost::archive::text_oarchive ArchiveT(AstreamT);
    ArchiveT << towers;
    std::string OdataT = AstreamT.str();
    out << OdataT;
    out.close();
}


void Engine::CheckTimeOut(){
    if(isAllDead() && !TimeOut){
        TimeOut = true;
        TimeOutClock.restart();
    }

    if(TimeOutClock.getElapsedTime().asSeconds() > TimeOutTime && TimeOut){
        FileLoaded = false;
        enemies.clear();
        newLevel();
        TimeOut = false;
        TimeOutTime = 10;
    }
}

void Engine::spawnEnemies(Types::NPC type){
    Enemy&& temp = Enemy(type, SpawnNumber, 0, 0);
    temp.InitializeSprite(0.f, 160.f);
    enemies.push_back(temp);
    SpawnNumber++;
}


void Engine:spawnEnemies(Types::NPC type, float x, float y, int flag, float distance){
    Enemy&& temp = Enemy(type, SpawnNumber, flag, distance);
    temp.InitializeSprite(x, y);
    enemies.push_back(temp);
    SpawnNumber++;
}


void Engine::spawnTower(Types::NPC type, float x, float y){
    Tower&& temp = Tower(this, type, x, y);
    temp.InitializeSprite();
    towers.push_back(temp);
}

// Loads the map from .txt - file into array
void Engine::loadMap(int id){
  std::string map_path = "map" + std::to_string(id) + ".txt";
  std::ifstream map_file(map_path);
  std::string pixel;

  int i = 0;
  int pixels[510];

  if(map_file.is_open()) {
    while(std::getline(map_file, pixel, ',')){
        pixels[i] = std::stoi(pixel);
        i++;
    }
    map_file.close();
  }

// Create the tilemap from the level definition
  TileMap map;
  if(!map.load("tilesheet.png", sf::Vector2u(32, 32), &pixels[0], 16, 8)){
      std::cout << "Can not load the map." << std::endl;
  }

}

// Updates the player to a next level
void Engine::LevelUp(){
    enemiesSpawned = 0;
    if(round < 3){
        MaxEnemies = BaseLevels[Level][0];
    } else {
        MaxEnemies = Level * 2;
    }

    money += 500;
    Level++;
    enemies.reserve(MaxEnemies);
    std::cout << "New level starting!" << std::endl;
}
