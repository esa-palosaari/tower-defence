#ifndef Tower_hpp
#define Tower_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Engine.hpp"
#include "Types.hpp"

// taytyyko engine forward declaroida?

class Tower {
    public:
        Tower {Engine* game, Types::NPC type, int x, int y);
        Tower() {};
        // implementoi funktiot 
        checkRange();
        shoot();
        getHit();
        checkAngle();
    private:
        types::NPC type;
        int range;
        int firerate;
        std::vector<int> Placement; // tarvitaanko tata vai korvataanko kahdella muuttujalla?
};
#endif