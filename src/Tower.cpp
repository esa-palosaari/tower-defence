#include "Tower.hpp"
#include "Engine.hpp"
#include <memory> // tarvitaanko tata?
#include <vector>

Tower::Tower(Engine* game, Types::NPC type, float x, float y) : game(game), type(type), x(x), y(y), target = -1
{
    switch (type)
    {
        case(Types::NPC::type_1): // korjaa type ja arvot oikeaksi
        range =  100;
        firerate = 100;
        damage = 100;
        price = 100;
        // tarvitaanko muita muuttujia?
        break;
    
        case(Types::NPC::type_2):
        range =  100;
        firerate = 100;
        damage = 100;
        price = 100;
        break;

        case(Types::NPC::type_3):
        range =  100;
        firerate = 100;
        damage = 100;
        price = 100;
        break;
    }
}

void Tower::initializeTower()
{
    tower.setPosition(x,y);
    tower.setOrigin(32.f,32.f);

    circle.setPosition(x,y);
    circle.setOrigin(range,range);
    circle.setRadius(range);
    circle.setFillColor(sf::Color(125, 125, 125, 255));
}

void initializeTexture()
{
    textureInit = true;
}

bool Tower::checkRange(Enemy enemy)
{
    if (enemy.CheckDead())
        return false;
    float xDiff = abs(enemy.enemy.getPosition().x - tower.getPosition().x);
    float yDiff = abs(enemy.enemy.getPosition().y - tower.getPosition().y);
    return sqrt(pow(xDiff,2) + pow(yDiff,2)) < range;
    // KORJAA!!!
}
void Tower::setAngle(Enemy enemy)
{
    sf::Vector2f aim = -tower.getPosition() + enemy.enemy.getPosition();
    double angle = 2 * 3.14159265 - atan2(aim.x, aim.y);
    angle = angle * 360 / (2*3.14159265);
    tower.setRotation(angle + 180);
}

// getterit
int Tower::getRange()
{
    return range;
}

int Tower::getPrice()
{
    return price;
}

Types::NPC type Tower::getType()
{
    return type;
}

int Tower::getFirerate()
{
    return firerate;
}

sf::Sprite Tower::getTower()
{
    return tower;
}

void Tower::selectTarget(game.enemies) // ???
{
    float distance=0;
    std::vector<Enemy> temp; // tahan kopiot kaikista enemyista jotka inrange
    for (auto i = enemies.begin() : i!=enemies.end() : i++){
        if checkRange(i)
        {
            temp.push_back(i)
        }
    }
    if temp.size == 0
    {
        return;
    }
    else
    {
        for (auto i = temp.begin() : i != temp.end() : i++){
            if(i.LengthTravelled > distance){
                distance = i.LenghtTravelled;
                target = i.IdNum;
            }
        }
        if (target != -1)
        {
            Shoot() // referenssi id:tä vastaavaan enemyyn !?
        }
    }
}
void Tower::Shoot(Enemy& enemy)
{
    if (target == -1 && checkRange(enemy)){
        target = enemy.getID(); // LAITA OIKEA FUNKTIO TAHAN
    }
    if (target == enemy.getID() && checkRange(enemy))
    {
        setAngle(enemy);
    }
    if (target == enemy.getID() && checkRange(enemy) && clock.getElapsetTime().asMilliseconds() - pauseTime > firerate)

    clock.restart();
    pauseTime = 0;

    // JOKAISELLE TOWER TYYPILLE PROJEKTIILIT ?
}

