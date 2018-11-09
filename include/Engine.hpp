#ifndef Engine_hpp
#define Engine_hpp

#include "Enemy.hpp"
#include "Tower.hpp"
#include "Projectile"
#include "TileMap.hpp"

#include <fstream>
#include <ctime>


class Engine{
public:
    void StartEngine();
    void Update(sf::Time TimeElapsed);
    int TimeToNextRound() {return TimeOutTime - TimeOutClock.getElapsedTime().asSeconds();}
    
    int getMoney() const {return money;};
    void loseMoney(int money) {money -= money;}
    int getLevel() const {return Level;}
    int getHP() const {return HP;}
    
    bool isTimeOut() {return TimeOut;}
    void resetTimeOut() {TimeOutTime = 0;}
    void increaseTimeOut(TimeOutTime += time;)
    bool isAllDead()
    bool isEnd() {return GameEnd;}
    
    void EndGame();
    void saveGame(std::string filetarget);
    
    void spawnTower(Types::NPC type, float x, float y);
    void spawnEnemies(Types::NPC type);
    void spawnEnemies(Types::NPC type, float x, float y, int flag, float distance)
    
    void setMoney(int startmoney) {money = startmoney;}
    void setHP(int startHP) {HP = startHP;}
    void setLevel(int startLevel) {Level = startLevel;}
    void setGameTag(std::string UserTag) {GameTag = UserTag;}
    
    TileMap map;
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    std::vector<Projectile> projectiles;
    
    
private:
    //Player's statistics
    std::string GameTag;
    int Level = 0;
    int HP = 100;
    int money = 1000;
    
    //Enemy information
    float spawnPointX = 0;
    float spawnPointY = 0;
    int SpawnNumber = 0;
    
    //Game's state information
    int TimeOutTime = 10;
    bool GameEnd = false;
    bool TimeOut = true;
    bool FileLoaded = false;
    
    //SFML properties
    sf::Clock TimeOutClock;
    sf::Clock Clock;
    
    //Required functions
    void loadMap(int Id);
    void newLevel();
    void watchForTimeout();
}



