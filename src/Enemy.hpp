#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Types.hpp"

class Enemy {
    public:
        Enemy(Types::NPC type, int IDNUM, int muuttuja, float lengthtravelled); //Object creator
        Enemy() {};
        move(sf::Vector2f position, sf::Time time); //Pathfinding
        getHit();
        EShoot();
        checkDistance();
        hit();
    private:
        Types::NPC type; //Type of enemy
        int Hp; //Healthpoints
        int IdNum;  //Identification number, check engine cpp.
        int Muuttuja=0; //Needed for pathfinding and setting rotation
        int Bounty; //Amount of money enemy drops when it dies.
        float Speed; //Enemy moves this fast.
        float LengthTravelled=0 //Distance from spawn
        bool Dead=false; //If object is dead or not
        sf::Vector2f Forward; //Move-function: Moves object 'forward'
        sf::Vector2f UpDown; //Move-function: Moves object down or up depending on position.
        sf::Vector2f Hold; //Move-function: Stops object from moving.
        int DMG;
        int x;
        int y;
};
#endif