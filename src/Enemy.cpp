#include "Enemy.hpp"


// Constructor, initializes the object according to type
Enemy::Enemy(Types::NPC Type, int IDNUM, int muuttuja, float lengthtravelled, float hpmodifier) : type(Type), IdNum(IDNUM), Muuttuja(muuttuja), LengthTravelled(lengthtravelled), LevelModifier(hpmodifier), Forward(200.f, 0.f), UpDown(0.f, 200.f), Hold(0.f,0.f) {
    switch(type){
        case(Types::NPC::Slow):
            Bounty = 16;
            Hp = 1000;
		         HpBase = 1000;
            Speed = 0.55;
            break;

        case(Types::NPC::Medium):
            Bounty = 16;
            Hp = 750;
		        HpBase = 750;
            Speed = 0.80;
            break;

        case(Types::NPC::Fast):
            Bounty = 16;
            Hp = 500;
		        HpBase = 500;
            Speed = 1.25;
            break;

      	case(Types::NPC::Commander):
        		Bounty = 22;
        		HpBase = 2000;
        		Hp = 2000;
        		Speed = 0.60;
        		break;

      	case(Types::NPC::Killer):
        		Bounty = 30;
        		HpBase = 4000;
        		Hp = 4000;
        		Speed = 0.60;
        		break;

      	case(Types::NPC::Aircraft):
        		Bounty = 16;
        		HpBase = 500;
        		Hp = 500;
        		Speed = 1.50;
        		break;
    }

	int HpModified = (int)(LevelModifier * Hp);
	Hp = HpModified;
	int HpBaseModified = (int)(LevelModifier * HpBase);
	HpBase = HpBaseModified;

}

// Moves the enemy according to its placement and type
void Enemy::Move(Types::NPC type, sf::Vector2f vector, sf::Time elapsedTime){

    if(Dead){
        return;
    }

	if(type == Types::NPC::Aircraft){
		if(vector.x >= 0){
      enemy.move(Speed * Forward * elapsedTime.asSeconds());
    }
		LengthTravelled += Speed * 1.25;
	}
	else {
		if(vector.x < 352){
      enemy.move(Speed * Forward * elapsedTime.asSeconds());

    		}
    		else if(vector.x >= 352 && vector.x < 800 && vector.y < 864){
          enemy.setRotation(90);
        	enemy.move(Speed*UpDown*elapsedTime.asSeconds());
    		}
    		else if(vector.x < 800 && vector.y >= 864){
          enemy.setRotation(0);
        	enemy.move(Speed * Forward * elapsedTime.asSeconds());
    		}
    		else if(vector.x >= 800 && vector.x < 1248 && vector.y >= 160){
          enemy.setRotation(270);
        	enemy.move(Speed *-UpDown * elapsedTime.asSeconds());
    		}
    		else if(vector.x >= 700 && vector.x < 1248 && vector.y < 160){
          enemy.setRotation(0);
        	enemy.move(Speed*Forward*elapsedTime.asSeconds());
    		}
    		else if(vector.x >= 1248 && vector.y < 864){
          enemy.setRotation(90);
        	enemy.move(Speed * UpDown * elapsedTime.asSeconds());
    		}
    		else if(vector.x >= 1000 && vector.y >= 864){
          enemy.setRotation(0);
        	enemy.move(Speed * Forward * elapsedTime.asSeconds());
    		}
    		else{
          enemy.move(Speed * Hold * elapsedTime.asSeconds());
    		}
    		LengthTravelled += Speed * 0.16;
	}
    if(type == Types::NPC::Slow || type == Types::NPC::Medium || Types::NPC::Fast || Types::NPC::Aircraft){
      HealthBar.setPosition(enemy.getPosition().x, enemy.getPosition().y + 20.f);
    }
    else {
      HealthBar.setPosition(enemy.getPosition().x, enemy.getPosition().y + 40.f);
    }
    base.setPosition(HealthBar.getPosition());
}

// Initializes enemy sprites
void Enemy::InitializeSprite(float PointX, float PointY){
    enemy.setPosition(PointX, PointY);
    HealthBar.setSize(sf::Vector2f(75,3));
    base.setSize(sf::Vector2f(75,3));
    HealthBar.setOrigin(37.f, 3/2.f);
    base.setOrigin(sf::Vector2f(37.f, 3/2.f));
    HealthBar.setFillColor(sf::Color::Green);
    base.setFillColor(sf::Color::Red);
    if(type == Types::NPC::Slow || type == Types::NPC::Medium || type == Types::NPC::Fast || type == Types::NPC::Commander){
      enemy.setOrigin(37.f, 37.f);
      HealthBar.setPosition(0.f, 140.f);
      base.setPosition(0.f, 140.f);
    }
	else {
		enemy.setOrigin(37.f, 37.f);
    HealthBar.setPosition(0.f, 890.f);
    base.setPosition(0.f, 890.f);
	}
}


// Getter functions
Types::NPC Enemy::getType() const{
    return type;
}

float Enemy::getLengthTravelled() const{
    return LengthTravelled;
}

int Enemy::getIdNum() const{
    return IdNum;
}

int Enemy::getHp(){
    return Hp;
}

int Enemy::getBounty() const{
    return Bounty;
}

bool Enemy::CheckDead(){
    return Dead;
}

// Sets enemy dead
void Enemy::setDead(){
    Dead = true;
}


// Damages enemy
int Enemy::getHit(int DMG){
    Hp -= DMG;
    if(Hp < 0){
        Hp = 0;
    }

    if(type == Types::NPC::Slow || type == Types::NPC::Medium || type == Types::NPC::Fast || Types::NPC::Commander){
        HealthBar.setSize(sf::Vector2f(75 * Hp / HpBase, 3));
    }

    if(Hp <= 0){
        enemy.setColor(sf::Color::Black);
        base.setFillColor(sf::Color::Transparent);
        Dead = true;
        clock.restart();
        return Bounty;
    }
    else {
        return 0;
    }
}


// Sets time to pause
void Enemy::setTimePause(float Time){
	PauseTime = Time;
}

// Initializes tectures
void Enemy::InitializeTexture(){
	TextureInitialize = true;
}
