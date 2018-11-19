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
    Tower {Engine* game, Types::NPC type, float x, float y);
    void InitializeSprite();
    void InitializeTexture();
    void Shoot(Enemy& enemy);
    void setTimePause(float Time) { TimePause = Time; }
    void ReTarget();
        //Getters
    int getRange();
    int getFirerate();
    int getPrice();
    sf::Sprite getTower();
    Types::NPC getType() const;
        //Values declared in public.
    sf::Sprite tower;
    sf::CircleShape circle;
    bool textureInitialize = false;
            
    template <typename Archive>
    void serialize(Archive& statistics, const unsigned int version){
        ValueType & type;
        ValueType & x;
        ValueType &y;
        ValueType &Damage;
        ValueType &range;
        ValueType &firerate;
    }
private:
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
