#include "Engine.hpp"
#include "UserGraphics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

bool Engine::isAllDead(){
    if(enemies.size() < 1){
        return true;
    }
    for(int i=0; i<enemies.size(); i++){
        if(!enemies[i].isDead()){   //Enemy class: isDead()
            return true;
        }
    }
    return false;
}
void Engine::EndGame(){
    if(!GameEnd){
        GameEnd=true;
    }
}
void Engine::saveGame(std::string targetPath){  
    std::ofstream out;
    out.open(targetPath, std::ios:app);
    out<<points<<';'<<round<<';'<<HP<<';';
    std::ostringstream archive_streamT;
    boost::archive::text_oarchive archiveT(archive_streamT);
    archiveT << towers;
    std::string outbound_dataT_ = archive_streamT.str();
    out<<outbound_dataT_;
    out.close();
}
void Engine::watchForTimeout(){
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
    temp.initSprite(0.f, 160.f);
    enemies.push_back(temp);
    SpawnNumber++;
}
void Engine::spawnTower(Types::NPC type, float x, float y){
    Tower&& temp = Tower(this, type, x, y);
    temp.initSprite();
    towers.push_back(temp);
}
void Engine::StartEngine(){
    loadMap(1);
    clock.restart();
    UserGraphics graph(this); //Kannattaako lähettää olio vai tietorakenne?
    graph.StartEngine();
}




