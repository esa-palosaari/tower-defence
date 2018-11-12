#include "Enemy.hpp"

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
