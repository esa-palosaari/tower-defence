#include "Tower.hpp"
#include "Engine.hpp"
#include <SFML/Audio.hpp>
#include <math.h>
#include <memory> //Jotta voidaan hallinnoida uusien tornien spawnaaminen ja mahdollinen tallentaminen save game-funktiossa.

Tower::Tower(Engine* engine, Types::NPC type, float x, float y) : engine(engine), type(type), x(x), y(y)
{
    switch (type)
    {
        case(Types::NPC::Machinegun):
        Range =  350;
        Firerate = 450;
        DMG = 100;
        Price = 500;
        break;

        case(Types::NPC::Flamethrower):
        Range =  275;
        Firerate = 45;
        DMG = 12;
        Price = 500;
        break;

        case(Types::NPC::Rocketlauncher):
        Range =  300;
        Firerate = 2000;
        DMG = 250;
        Price = 500;
        break;
    }
}

//Initializes tower's sprite
void Tower::InitializeSprite() {

    tower.setPosition(x,y);
    tower.setOrigin(32.f,32.f);

  	infopanel.setPosition(1690,550);
  	infopanel.setScale(0.5f,0.26f);

    circle.setPosition(x,y);
    circle.setOrigin(Range,Range);
    circle.setRadius(Range);
    circle.setFillColor(sf::Color(125, 125, 125, 255));
}

//Initializes texture for tower.
void Tower::InitializeTexture() {
    textureInitialize = true;
}

// Getters
int Tower::getRange(){
    return Range;
}

int Tower::getPrice(){
    return Price;
}

Types::NPC Tower::getType () const{
    return type;
}

int Tower::getFirerate(){
    return Firerate;
}

int Tower::getDMG(){
	return DMG;
}

//Sprite is named 'tower'
sf::Sprite Tower::getTower(){
    return tower;
}

// Shooting phase functions.
// Called from Engine.cpp to every tower after every tower has fired per frame.
void Tower::ReTarget(){
    TargetID = -1;
}


//
void Tower::Shoot(Enemy& enemy) {

    //TargetID is -1, when there is no target, but changes when there is potential enemy in range.
    if (TargetID == -1 && inRange(enemy)){
        TargetID = enemy.getIdNum();
    }

    // Checks if targeted enemy has same targetID compared to turret's.
    if (TargetID == enemy.getIdNum() && inRange(enemy)){
        AimAngle(enemy);    // If so, turret aims at the enemy.
    }

    // Lastly, turret checks whether enough time has passed since last shot. Time hast to be more than firerate.
    if (TargetID == enemy.getIdNum() && inRange(enemy) && (clock.getElapsedTime().asMilliseconds() - TimePause) > Firerate){
        clock.restart();    // clock is restarted, which means that shots are fired.
        TimePause = 0;      // TimePause is resetted.
        if(type == Types::NPC::Machinegun){       // Depending on each turrets type, different kind of projectile is fired.
            //Projectiles vector is updated.
            engine->projectiles.push_back(std::make_shared<MachinegunProjectile>(MachinegunProjectile(DMG, x, y, type, enemy.getIdNum())));
			      shootSound.play();
        } else if (type == Types::NPC::Flamethrower){
            engine->projectiles.push_back(std::make_shared<FlameProjectile>(FlameProjectile(DMG, x, y, type, enemy.getIdNum())));
			      shootSound.play();
        } else if(type == Types::NPC::Rocketlauncher){
            engine->projectiles.push_back(std::make_shared<RocketProjectile>(RocketProjectile(DMG, x, y, type, enemy.getIdNum())));
			      shootSound.play();
        }
    }
}


// Checks if targeted enemy is in range. Called from tower's Shoot()-function.
bool Tower::inRange(Enemy enemy){
    if (enemy.CheckDead()){
         return false;
    }

    float XLength = abs(enemy.enemy.getPosition().x - tower.getPosition().x);
    float YLength = abs(enemy.enemy.getPosition().y - tower.getPosition().y);
    return sqrt(pow(XLength, 2) + pow(YLength, 2)) < Range;
}

// Alters tower's sprite to face enemy's direction. Called from tower's Shoot() -function.
void Tower::AimAngle(Enemy enemy) {
    sf::Vector2f SightAngle = -tower.getPosition() + enemy.enemy.getPosition();
    double Angle = 2 * 3.14159265 - atan2(SightAngle.x, SightAngle.y);
    Angle = Angle * 360 / (2*3.14159265);
    tower.setRotation(Angle + 180);
}

// Alters tower's level, dmg, range and money
void Tower::setTowerLevel(){
	DMG = DMG * 2;
	Range += 5;

	switch(this->TowerLevel){
		case(1):
			engine->loseMoney(200);
			break;
		case(2):
			engine->loseMoney(400);
			break;
		case(3):
			engine->loseMoney(800);
			break;
	}

	TowerLevel++;
	upgradeSound.play();
  
}
