#ifndef Projectile_hpp
#define Projectile_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Engine.hpp"
#include "Types.hpp"

// taytyyko engine forward declaroida?

class Projectile {
    public:
        Projectile {Engine* game, Types::NPC type, int x, int y);
        Projectile() {};
        // tarvitaanko muita funktioita?
        move();
        hit();
        checkGoal();
    private:
        types::NPC type;
        // tarvitaanko nopeus ja suunta?
        int DMG;
        std::vector<int> Placement; // tarvitaanko tata vai korvataanko kahdella muuttujalla x ja y ?
};
#endif