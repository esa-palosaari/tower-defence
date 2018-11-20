#include "Projectile.hpp"

Projectile::Projectile(int dmg, float x, float y, Types::NPC Type, int targetId) : DMG(dmg), x(x), y(y), type(Type), TargetID(targetId) {}

void Projectile::InitializeTexture(){
    textureInitialize = true;
}

sf::Sprite Projectile::getProjectileSprite() const{
    return ProjectileSprite;
}

Types::NPC Projectile::getProjectileType() const{
    return type;
}

bool Projectile::isBlownUp(){   //Check's if projectile exists or not.
    return BlownUp;
}

void Projectile::Move(sf::Time elapsedTime, std::vector<Enemy>& enemies){
    for(auto& enemy : enemies){
        if(enemy.getIdNum()==TargetID){     //Check's if targeted enemy is right one for all existing enemies.
            sf::Vector2f AimAtTarget = -ProjectileSprite.getPosition() + enemy.enemy.getPosition();     //Builds a vector to targeted enemy.
            float AimAngle = 2 * 3.1415 - atan2(AimAtTarget.x, AimAtTarget.y);      //Builds a required angle to guide projectile to right position.
            AimAngle = AimAngle * 360/(2*3.1415);       //Changes angle to radians.
            ProjectileSprite.setRotation(AimAngle+180); //Rotates projectile correctly.
            float AimPower = sqrt(pow(AimAtTarget.x,2)+pow(AimAtTarget.y,2));   //Calculates distance to target.
            sf::Vector2f UnitVector(AimAtTarget.x / AimPower, AimAtTarget.y / AimPower);    //Creates unit vector to target.
            ProjectileSprite.move(Speed*UnitVector*elapsedTime.asSeconds());    //Calls sprite's move-function (need to implement this!) to move projectile. move() is SFML-based function.
            break;
        }
    }
}

MachinegunProjectile::MachinegunProjectile(int dmg, float x, float y, Types::NPC type, int targetId) : Projectile(dmg, x, y, type, targetId){
    ProjectileSprite.setPosition(x,y);
    ProjectileSprite.setOrigin(32.f, 32.f);
}

int MachinegunProjectile::HitTarget(std::vector<Enemy>& enemies){
    int number = 0;
    for(auto& enemy : enemies){
        if(enemy.getIdNum() == TargetID && abs(ProjectileSprite.getPosition().x - enemy.enemy.getPosition().x) <= 10 && abs(ProjectileSprite.getPosition().y-enemy.enemy.getPosition().y) <= 10 && BlownUp == false){ //Checks if enemy is close enough to projectile and projectile still exists.
            if(!enemy.CheckDead()){
                number = enemy.getHit(DMG);     //if enemy is not dead, it gets hit. It drops bounty if it dies, otherwise returns zero.
            }
            BlownUp=true;              //Projectile itself is "blown up" and doesn't exist anymore.
            break;
        }
    }
    return number;
}

FlameProjectile::FlameProjectile(int dmg, float x, float y, Types::NPC type, int targetId) : Projectile(dmg, x, y, type, targetId){
    ProjectileSprite.setPosition(x,y);
    ProjectileSprite.setOrigin(32.f, 32.f);
}

int FlameProjectile::HitTarget(std::vector<Enemy>& enemies){
    int number=0;
    for(auto& enemy : enemies){
        if(enemy.getIdNum() == TargetID && abs(ProjectileSprite.getPosition().x - enemy.enemy.getPosition().x) <= 10 && abs(ProjectileSprite.getPosition().y-enemy.enemy.getPosition().y) <= 10 && BlownUp == false){
            if(!enemy.CheckDead()){
                number = enemy.getHit(DMG);      //Same as machinegun's projectile. Additional features will be added here once the basic mechanism works.
            }
            BlownUp = true;
            break;
        }
    }
    return number;
}

RocketProjectile::RocketProjectile(int dmg, float x, float y, Types::NPC, int targetId) : Projectile(dmg, x, y, type, targetId){
    ProjectileSprite.setPosition(x,y);
    ProjectileSprite.setOrigin(32.f, 32.f);
}

int RocketProjectile::HitTarget(std::vector<Enemy>& enemies){
    int number = 0;
    for(auto& enemy : enemies){
        if(enemy.getIdNum() == TargetID && abs(ProjectileSprite.getPosition().x - enemy.enemy.getPosition().x) <= 10 && abs(ProjectileSprite.getPosition().y-enemy.enemy.getPosition().y) <= 10 && BlownUp == false){
            if(!enemy.CheckDead()){
                number = enemy.getHit(DMG);    //Target itself gets hit as normally.
            }
            AoE.setOrigin(46.f, 45.f);      //Area of effect damage is implicated.
            AoE.setScale(2,2);
            AoE.setPosition(enemy.enemy.getPosition().x, enemy.enemy.getPosition().y);  //Are of effect sprite is placed above enemy hit.
            AoD.setOrigin(100.f, 100.f);                                                //This is just a sprite, it doesn't "hurt" enemies.
            AoD.setRadius(100); //Damage area's radius is set.
            AoD.setPosition(enemy.enemy.getPosition().x, enemy.enemy.getPosition().y);  //Area of damage sprite is placed above enemy hit.
            AoD.setFillColor(sf::Color(216,30,0,100));                                  //This effect hurts all enemies that are inside its radius.
            for(auto& enemi: enemies){  //Damages all enemies that are caught inside are of damage.
                if(AoD.getGlobalBounds().contains(enemi.enemy.getPosition().x, enemi.enemy.getPosition().y) && !enemi.CheckDead()){
                    if(!enemi.CheckDead()){
                        number+=enemi.getHit(DMG);
                    }
                }
            }
            GraphArea = true;       //Changes GraphArea to true.
            clock.restart();        //Restarts the clock.
            BlownUp=true;           //Destroys projetile.
            break;
        }
    }
    return number;
}



