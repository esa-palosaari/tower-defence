#ifndef Tower_hpp
#define Tower_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Engine.hpp"
#include "Types.hpp"

class Engine;

class Tower {
public:
    Tower (Engine* game, Types::NPC type, float x, float y);
    void InitializeSprite();
    void InitializeTexture();
    void Shoot(Enemy& enemy);
    void setTimePause(float Time) { TimePause = Time; }
    void ReTarget();
    //Getters
    int getRange();
    int getFirerate();
    int getPrice();
  	int getDMG();
  	int getTowerLevel() { return TowerLevel;}

  	void setTowerLevel();
    sf::Sprite getTower();
    Types::NPC getType() const;
    sf::Sprite tower;
    sf::CircleShape circle;
  	sf::Sprite infopanel;
  	sf::Sound shootSound;
  	sf::Sound upgradeSound;
    bool textureInitialize = false;
  	bool UpgradeClick = false;
  	bool UpgradeLevel = true;
  	int TowerLevel = 1;


private:
    sf::Clock clock;
    sf::Font font;
    void AimAngle(Enemy const enemy);
    bool inRange(Enemy const enemy);
    Types::NPC type;
    Engine* engine;
    float Range;
    int Firerate;
    int DMG;
    int Price;
    int TargetID;
    float x;
    float y;
    float TimePause = 0;

};

#endif
