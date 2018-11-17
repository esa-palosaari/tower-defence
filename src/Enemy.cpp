#include "Enemy.hpp"

Enemy::Enemy(Engine* game, Types::NPC Type, int IDNUM, int muuttuja, float lengthtravelled) : type(Type), IdNum(IDNUM), Muuttuja(muuttuja), LengthTravelled(lengthtravelled), Forward(200.f, 0.f), UpDown(0.f, 200.f), Hold(0.f,0.f) {
    switch(type){
        case(Types::NPC::Slow):
            Bounty = 50;
            Hp=1500;
            Speed=0.75;
	    enemy = game.graph.spriteEnemy1
            break;
    
        case(Types::NPC::Medium):
            Bounty = 50;
            Hp=1000;
            Speed=1.0;
	    enemy = game.graph.spriteEnemy2	    
            break;
            
        case(Types::NPC::Fast):
            Bounty=50;
            Hp=500;
            Speed=1.25;
	    enemy = game.graph.spriteEnemy3	    
            break;
    }
}
void Enemy::Move(sf::Vector2f vector, sf::Time elapsedTime){
    if(Dead){
        return;
    }
    if(vector.x<352){
        enemy.move(Speed*Forward*elapsedTime.asSeconds());
        
    }
    else if(vector.x >= 352 && vector.xx < 800 && vector.y < 864){
        if(Muuttuja <= 0){
            Muuttuja=1;
            enemy.setRotation(90);
        }
        enemy.move(Speed*UpDown*elapsedTime.asSeconds());
    }
    else if(vector.x<800 && vector.y >= 864){
        if(Muuttuja==1){
            Muuttuja==2;
            enemy.setRotation(0);
        }
        enemy.move(Speed*-UpDown*elapsedTime.asSeconds());
    }
    else if(vector.x >= 800 && vector.x < 1248 && vector.y >= 160){
        if(Muuttuja==2){
            Muuttuja=3;
            enemy.setRotation(-90);
        }
        enemy.move(Speed*-UpDown*elapsedTime.asSeconds());
    }
    else if(vector.x>=700 && vector.x<1248 && vector.y < 160){
        if(Muuttuja==3){
            Muuttuja=4;
            enemy.setRotation(0);
        }
        enemy.move(Speed*Forward*elapsedTime.asSeconds());
    }
    else if(vector.x >= 1248 && vector.y < 864){
        if(Muuttuja==4){
            Muuttuja=5;
            enemy.setRotation(90);
        }
        enemy.move(Speed*UpDown*elapsedTime.asSeconds());
    }
    else if(vector.x >= 1000 && vector.y >=864){
        if(Muuttuja==5){
            Muuttuja=6;
            enemy.setRotation(0);
        }
        enemy.move(Speed*Forward*elapsedTime.asSeconds());
    }
    else{
        enemy.move(Speed*Hold*elapsedTime.asSeconds());
    }
    LengthTravelled += Speed * 0.16;
    if(type == Types::NPC::Slow || type==Types::NPC::Medium || Types::NPC::Fast){
        HealthBar.setPosition(enemy.getPosition().x, enemy.getPosition().y+20.f);
    }
    else{
        HealthBar.setPosition(enemy.getPosition().x, enemy.getPosition().y+40.f);
    }
    base.setPosition(HealthBar.getPosition());
}
void Enemy::InitializeSprite(float PointX, float PointY){
    enemy.setPosition(PointX, PointY);
    HealthBar.setSize(sf::vector2f(64,3));
    base.setSize(sf::Vector2f(64,3));
    HealthBar.setOrigin(32.f, 3/2.f);
    base.setOrigin(sf::Vector2f(32.f, 3/2.f));
    HealthBar.setFillColor(sf::Color::Green);
    base.setFillColor(sf::Color::Red);
    if(type==Types::NPC::Slow || type==Types::NPC::Medium || type==Types::NPC::Fast){
        enemy.setOrigin(32.f, 32.f);
        HealthBar.setPosition(0.f, 140.f);
        base.setPosition(0.f, 140.f);
    }
}
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
void Enemy::setDead(){
    Dead=true;
}
bool Enemy::CheckDead(){ 
    return Dead;
}
int Enemy::getHit(int DMG){
    Hp -= DMG;
    if(Hp<0){
        Hp=0;
    }
    if(type==Types::NPC::Slow || type==Types::NPC::Medium || type==Type::NPC::Fast){
        HealthBar.setSize(sf::Vector2f(HP * 8 / 125, 3));
    }
    if(Hp<=0){
        enemy.setColor(sf::Color::Black);
        base.setFillColor(sf::Color::Transparent);
        Dead=true;
        clock.restart();
        return Bounty;
    }
    else{
        return 0;
    }
}

void Monster::setTimePause(float Time){
	PauseTime = Time;
}
void Monster::InitializeTexture(){
	TextureInitialize = true;
}