#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Types.hpp"

class Enemy {
    public:
  	Enemy(Types::NPC type, int IDNUM, int muuttuja, float lengthtravelled, float hpmodifier); // Constructor
        void Move(sf::Vector2f position, sf::Time time); //Pathfinding
        int getHit(int DMG); //Enemy gets hit by projectile and loses health. Returns bounty if dies.
        void InitializeSprite(float PointX, float PointY); //Initializes enemy's sprite to spawnpoint.
        Types::NPC getType() const; //Getter
        float getLengthTravelled() const; //Getter
        int getIdNum() const; //Getter
        int getHp(); //Getter
        int getBounty() const; //Getter
        void setDead(); //Changes enemy's status to Dead=true;
        bool CheckDead(); //Checks if enemy is dead or not
        void setTimePause(float Time);
        void InitializeTexture();
        
        bool TextureInitialize = false;
        bool operator<(const Enemy& E) const{return (LengthTravelled < E.LengthTravelled);} //Operator overloading for sorting different enemies when calculating which one to shoot at.
    
        sf::Sprite enemy;
        sf::RectangleShape HealthBar;
        sf::RectangleShape base;
        sf::Clock clock;

    private:
        Types::NPC type; //Type of enemy
        int Hp; //Healthpoints
        int IdNum;  //Identification number, check engine cpp.
        int Muuttuja=0; //Needed for pathfinding and setting rotation
        int Bounty; //Amount of money enemy drops when it dies.
        float Speed; //Enemy moves this fast.
        float LengthTravelled = 0; //Distance from spawn
        float PauseTime = 0;
	float LevelModifier;
        bool Dead=false; //If object is dead or not
        sf::Vector2f Forward; //Move-function: Moves object 'forward'
        sf::Vector2f UpDown; //Move-function: Moves object down or up depending on position.
        sf::Vector2f Hold; //Move-function: Stops object from moving.
};

#endif
