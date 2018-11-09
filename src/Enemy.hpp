#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Engine.hpp"
#include "Types.hpp"

// taytyyko engine forward declaroida?

class Enemy {
    public:
        Enemy {Engine* game, Types::NPC type, int x, int y);
        Enemy() {};
        // tarvitaanko muita funktioita?
        move();
        getHit();
        EShoot();
        checkDistance();
        hit();
    private:
        types::NPC type;
        int HP;
        int moveRate;
        int DMG;
        int x;
        int y;
};
#endif