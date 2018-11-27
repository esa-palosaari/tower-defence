#ifndef Engine_hpp
#define Engine_hpp

#include "Enemy.hpp"
#include "Tower.hpp"
#include "Projectile.hpp"
#include "TileMap.hpp"

#include "Types.hpp"    //U
#include "memory"   //U

#include <fstream>
#include <ctime>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/serialization/vector.hpp>

    class Tower;
    class Projectile;    // forward declaration?
    
class Engine{
public:
    void StartEngine();
    void Update(sf::Time TimeElapsed);
    int TimeToNextRound() {return TimeOutTime - TimeOutClock.getElapsedTime().asSeconds();}

    int getMoney() const {return money;};
	int getScore() const {return score;}
    void loseMoney(int cash) {money -= cash;}
    int getLevel() const {return Level;}
    int getHP() const {return HP;}

    bool isTimeOut() {return TimeOut;}
    void resetTimeOut() {TimeOutTime = 0;}
    void increaseTimeOut(int time){TimeOutTime += time;}
    bool isAllDead();
    bool isEnd() {return GameEnd;}

    void EndGame();
    void saveGame(std::string filetarget);

    void spawnTower(Types::NPC type, float x, float y);
    void spawnEnemies(Types::NPC type);
    void spawnEnemies(Types::NPC type, float x, float y, int flag, float distance);

    void setMoney(int startmoney) {money = startmoney;}
    void setHP(int startHP) {HP = startHP;}
    void setLevel(int startLevel) {Level = startLevel;}
    void setGameTag(std::string UserTag) {GameTag = UserTag;}

    TileMap map;
    sf::RenderWindow window;
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    std::vector<std::shared_ptr<Projectile>> projectiles;   // projectile is an abstract class
	


private:
    // Player's statistics
    std::string GameTag;
    int Level = 0;
    int HP = 10;
	int money=0;
	int score=0;


    // Enemy information
    float spawnPointX = 0;
    float spawnPointY = 0;
    int SpawnNumber = 0;
    int MaxEnemies = 0;
    int SpawnedSlows = 0;
    int SpawnedMediums = 0;
    int SpawnedFasts = 0;
	int SpawnedCommanders=0;
	int SpawnedKillers=0;
	int SpawnedAircrafts=0;
    int BaseLevels[4][4] = {{5,0,0,0},{0,5,0,0},{0,0,5,0},{0,0,0,1}};

    // Game's state information
    int Interval = 750;
    int TimeOutTime = 10;
    bool GameEnd = false;
    bool TimeOut = true;
    bool FileLoaded = false;

    // SFML properties
    sf::Clock TimeOutClock;
    sf::Clock clock;

    // Required functions
    void loadMap(int Id);
    void LevelUp();
    void CheckTimeOut();
};

#endif 
