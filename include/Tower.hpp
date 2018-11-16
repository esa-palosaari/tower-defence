#ifndef Tower_hpp
#define Tower_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Engine.hpp"
#include "Types.hpp"

class Engine; // taytyyko engine forward declaroida?

class Tower {
    public:
        Tower {Engine* game, Types::NPC type, float x, float y);
        Tower() {};
        // implementoi funktiot 
        sf::Sprite tower;
        sf::CircleShape circle;
        bool textureInit = false;
        void initializeTower();
        void initializeTexture();
        bool checkRange(Enemy const enemy);
        void Shoot(Enemy& enemy);
        void setAngle(Enemy const enemy);
        void ReTarget(); // kutsuu checkrangea, in range valitsee pisimmalle vaeltaneen enemyn
        int getRange(); // etsii 
        int getFirerate();
        int getPrice();
        sf::Sprite getTower();
        Types::NPC getType() const;
    private:
        Types::NPC type;
        Engine* game; // ?
        float range;
        int firerate;
        int damage;
        int price;
        float x;
        float y; // tarvitaanko tata vai korvataanko kahdella muuttujalla?
};
#endif