#include "Tower.hpp"
#include "Engine.hpp"
#include <memory> //Jotta voidaan hallinnoida uusien tornien spawnaaminen ja mahdollinen tallentaminen save game-funktiossa.

Tower::Tower(Engine* engine, Types::NPC type, float x, float y) : engine(engine), type(type), x(x), y(y)
{
    switch (type)
    {
        case(Types::NPC::Machinegun):
        Range =  100;
        Firerate = 100;
        DMG = 100;
        Price = 100;
        break;
    
        case(Types::NPC::Flamethrower):
        Range =  100;
        Firerate = 100;
        DMG = 100;
        Price = 100;
        break;

        case(Types::NPC::Rocketlauncher):
        Range =  100;
        Firerate = 100;
        DMG = 100;
        Price = 100;
        break;
    }
}

//SFML initialization.

void Tower::InitializeSprite()      //Initializes tower's sprite
{
    tower.setPosition(x,y);
    tower.setOrigin(32.f,32.f);

    circle.setPosition(x,y);
    circle.setOrigin(range,range);
    circle.setRadius(range);
    circle.setFillColor(sf::Color(125, 125, 125, 255));
}

void Tower::InitializeTexture() //Initializes texture for tower.
{
    textureInitialize = true;
}

//Getters
int Tower::getRange()
{
    return Range;
}

int Tower::getPrice()
{
    return Price;
}

Types::NPC type Tower::getType()
{
    return type;
}

int Tower::getFirerate()
{
    return Firerate;
}

sf::Sprite Tower::getTower()    //Sprite is named 'tower'
{
    return tower;
}

//Shooting phase functions.

void Tower::ReTarget(){ //Called from Engine.cpp to every tower after every tower has fired per frame.
    TargetID = -1;
}

void Tower::Shoot(Enemy& enemy)     //Called from Engine.cpp
{
    if (TargetID == -1 && inRange(enemy)){  //TargetID is -1, when there is not target, butchanges when there is potential enemy in range.
        TargetID = enemy.getIdNum();
    }
    if (TargetID == enemy.getIdNum() && inRange(enemy)) //Checks if targeted enemy has same targetID compared to turret's.
    {
        AimAngle(enemy);    //If so, turret aims at the enemy.
    }
    if (TargetID == enemy.getIdNum() && inRange(enemy) && clock.getElapsetTime().asMilliseconds() - TimePause > Firerate){  //Lastly, turret checks whether enough time has passed since last shot. Time hast to be more than firerate.
        clock.restart();    //clock is restarted, which means that shots are fired.
        TimePause = 0;      //TimePause is resetted.
        if(type==Types::NPC::Machinegun){       //Depending on each turrets type, different kind of projectile is fired.
            std::shared_ptr<MachinegunProjectile> projectile = std::make_shared<MachinegunProjectile>(DMG, x, y, type, enemy.getIdNum());   //Projectiles are tracked using shared pointers.
            engine->projectiles.pusch_back(projectile); //Projectiles vector is updated.
        }
        else if(type == Types::NPC::Flamethrower){
            std::shared_ptr<FlameProjectile> p = std::make_shared<FlameProjectile>(DMG, x, y, type, enemy.getIdNum());
            engine->projectiles.push_back(p);
        }
        else if(type == Types::NPC::Rocketlauncher){
            std::shared_ptr<RocketProjectile> p = std::make_shared<RocketProjectile>(DMG, x, y, type, enemy.getIdNum());
            engine->projectiles.push_back(p);
        }
    }
}

bool Tower::inRange(Enemy enemy)    //This checks if targeted enemy is in range. Called from tower's Shoot()-function.
{
    if (enemy.CheckDead()){
         return false;
    }
    float XLength = abs(enemy.enemy.getPosition().x - tower.getPosition().x);
    float YLength = abs(enemy.enemy.getPosition().y - tower.getPosition().y);
    return sqrt(pow(XLength,2) + pow(YLength,2)) < Range;
}
void Tower::AimAngle(Enemy enemy)   //This alters tower's sprite to face enemy's direction. Called from tower's Shoot() -function.
{
    sf::Vector2f SightAngle = -tower.getPosition() + enemy.enemy.getPosition();
    double Angle = 2 * 3.14159265 - atan2(SightAngle.x, SightAngle.y);
    Angle = Angle * 360 / (2*3.14159265);
    tower.setRotation(Angle + 180);
}
