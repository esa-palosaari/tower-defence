#include "Engine.hpp"
#include "UserGraphics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

void Engine::StartEngine(){
    loadMap(1);
    Clock.restart();
    UserGraphics graph(this); //Kannattaako lähettää olio vai tietorakenne?
    graph.StartEngine();
}

void Engine::Update(sf::Time elapsedTime){
    if(Level == 0 || FileLoaded){
        CheckTimeout();
    }
    else{
        for(auto& enemy:enemies){
            auto EnemyPlacement = enemy.enemy.getPlacement(); //Enemy
            enemy.Move(EnemyPlacement, elapsedTime; //Enemy
            if(enemy.enemy.getPlacement().x >= 1984 && !enemy.isDead()){
                if(HP>0){
                    switch(enemy.getType()){
                        case(Types::NPC::Type_4):
                            HP=HP-1;
                            break;
                    }
                }
                enemy.Die();    //Enemy
            }
        }
        std::sort(enemies.rbegin(), enemies.rend());
        for(auto& enemy: enemies){
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
            if(!i->get()->DoesntExist()){       //Projectile
                i->get()->move(elapsedTime, enemies);   //Projectile
                i++;
            }
            else{
                i=projectiles.Remove(i);    //Projectile
            }
        }
        if(Level<=3){
            if(Clock.getElapsedTime().asMilliseconds() > Interval && enemiesSpawned < BaseLevels[Level-1][0]){
                spawnEnemies(Types::NPC::Type_4);
                enemiesSpawned++;
                Clock.restart();
            }
        }
        else{
            if(Clock.getElapsedTime().asMilliseconds()>Interval && enemies.size() < MaxEnemies){
                spawnEnemies(Types::NPC::Type_4);
                Clock.restart();
            }
        }
        if(enemies.size() == MaxEnemies && HP > 0){
            CheckTimeOut();
        }
    }
}

bool Engine::isAllDead(){
    if(enemies.size() < 1){
        return false;
    }
    for(int i=0; i<enemies.size(); i++){
        if(!enemies[i].isDead()){   //Enemy class: isDead()
            return false;
        }
    }
    return true;
}
void Engine::EndGame(){
    if(!GameEnd){
        GameEnd=true;
    }
}
void Engine::saveGame(std::string targetPath){
    std::ofstream out;
    out.open(targetPath, std::ios:app);
    out<<money<<';'<<Level<<';'<<HP<<';';
    std::ostringstream AstreamT;
    boost::archive::text_oarchive ArchiveT(AstreamT);
    ArchiveT << towers;
    std::string OdataT = AstreamT.str();
    out<<OdataT;
    out.close();
}
void Engine::CheckTimeOut(){
    if(isAllDead() && !TimeOut){
        TimeOut=true;
        TimeOutClock.restart();
    }
    if(TimeOutClock.getElapsedTime().asSeconds()>TimeOutTime && TimeOut){
        FileLoaded = false;
        enemies.clear();
        newLevel();
        TimeOut=false;
        TimeOutTime=10;
    }
}
void Engine::spawnEnemies(Types::NPC type){
    Enemy&& temp = Enemy(type, SpawnNumber, 0, 0);
    temp.initSprite(0.f, 160.f);
    enemies.push_back(temp);
    SpawnNumber++;
}
void Engine:spawnEnemies(Types::NPC type, float x, float y, int flag, float distance){
    Enemy&& temp = Enemy(type, SpawnNumber, flag, distance);
    temp.initSprite(x, y);
    enemies.push_back(temp);
    SpawnNumber++;
}
void Engine::spawnTower(Types::NPC type, float x, float y){
    Tower&& temp = Tower(this, type, x, y);
    temp.initSprite();
    towers.push_back(temp);
}
void Engine::loadMap(int Id){
    std::string MPath = "Kartta"+std::to_string(Id)+".txt";
    std::ifstream MFile(MPath);
    std::string Value;
    int i=0;
    int level[510];
    while(std::getline(MFile,Value,',')){
        level[i]=std::stoi(Value);
        i++;
    }
    if(!map.load("TileRange.png", sf::Vector2u(64,64), level, 30, 17)){
        std::cout<<"Can not load the map."<<std::endl;
    }
}
void Engine::LevelUp(){
    enemiesSpawned = 0;
    if(round < 3){
        MaxEnemies= BaseLevels[Level][0];
    }
    else{
        MaxEnemies = Level * 2;
    }
    money +=500;
    Level++;
    enemies.reserve(MaxEnemies);
    std::cout<<"New level starting!"<<std::endl;
}







