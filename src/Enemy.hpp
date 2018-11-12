#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Types.hpp"

class Enemy {
    public:
        Enemy {Engine* game, Types::NPC type, int x, int y);
        Enemy() {};
        move();
        getHit();
        EShoot();
        checkDistance();
        hit();
    private:
        Types::NPC type;
        int Hp;
        bool Dead=false;
        int Muuttuja=0; //Move-funktiossa käytettävä.
        float Speed;
        float LengthTravelled=0;
        sf::Vector2f Forward; //Move-function: Moves object 'forward'
        sf::Vector2f UpDown; //Move-function: Moves object down or up depending on position.
        sf::Vector2f Hold; //Move-function: Stops object from moving.
        int DMG;
        int x;
        int y;
};
#endif