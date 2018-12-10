#ifndef Projectiles_hpp
#define Projectiles_hpp
#include "Types.hpp"
#include "Tower.hpp"

class Projectile{
public:
    Projectile(int dmg, float x, float y, Types::NPC Type, int targetId);       //Constructor
    void InitializeTexture();   //Initializes textures.
    bool isBlownUp();
    virtual void Move(sf::Time elapsedTime, std::vector<Enemy>& enemies);   //Move-method for each projectile
    virtual int HitTarget(std::vector<Enemy>& enemies) = 0; //HitTarget-function is initialized to zero in case no enemies.
    
    //Getters
    Types::NPC getProjectileType() const;   //Returns Projectile's type (Machinegun, Flame or Rocket
    sf::Sprite getProjectileSprite() const; //Return projectile's sprite, which is initialized at UserGraphics constructor.
    
    //SFML properties
    sf::Clock clock;    //clock
    sf::Sprite AoE;     // Area of effect. This doesn't affect physically objects.
    sf::Sprite ProjectileSprite;    //Sprite for each projectile. Initialized at UserGraphics.
    sf::CircleShape AoD;    //Area of damage. This hurts everything inside it.
    
    //Properties that are needed in public declaration.
    bool textureInitialize = false; //Info whether texture is initialized or not.
    bool GraphArea = false; //Contains information whether Aoe is graphde or not.
    
    //These are needed to complete rule of five.
   /* virtual ~Projectile() {}    //Destructor
    Projectile(const Projectile&) = default;    //Copy constructor
    Projectile(Projectile&&) = default;          //Move constructor
    Projectile& operator=(const Projectile&) & = default;  //Copy assignment
    Projectile& operator=(Projectile&&) & = default;     //move assignment*/

protected:
    Types::NPC type;    //type of projectile, specific to each turret
    int DMG;    //Damage of each projectile
    float x;    //Position x-coordinate for vector::2f
    float y;    //Position y-coordinate for vector::2f
    float Speed=500; //Projectile's speed
    int TargetID;   //Enemy's identification number;
    bool BlownUp = false; //Used to check whether projectile exists or not.
};

class MachinegunProjectile : public Projectile{
public:
    MachinegunProjectile(int dmg, float x, float y, Types::NPC type, int targetId);
    int HitTarget(std::vector<Enemy>& enemies);
private:
    float Speed = 2000;
};

class FlameProjectile : public Projectile{
public:
    FlameProjectile(int dmg, float x, float y, Types::NPC type, int targetId);
    int HitTarget(std::vector<Enemy>& enemies);
private:
    float Speed = 1250;
};

class RocketProjectile : public Projectile{
public:
    RocketProjectile(int dmg, float x, float y, Types::NPC type, int targetId);
    int HitTarget(std::vector<Enemy>& enemies);
private:
    float Speed = 600;
};

#endif
