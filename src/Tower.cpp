#include "Tower.hpp"
#include "Engine.hpp"
#include <memory> // tarvitaanko tata?
#include <vector>

Tower::Tower(Engine* game, Types::NPC type, int x, int y) : game(game), type(type), x(x), y(y)
{
    switch (type)
    {
        case(Types::NPC::type_1): // korjaa type ja arvot oikeaksi
        int range =  100;
        int firerate = 100;
        // tarvitaanko muita muuttujia?
        break;
    
        case(Types::NPC::type_2):
        int range = 200;
        int firerate = 200;
        break;

        case(Types::NPC::type_3):
        int range = 300;
        int firerate = 300;
        break;
    }
}

float Tower::checkRange()
{

}
void Tower::shoot()
{

}
void getHit();
{

}
std::vector<int> Tower::checkAngle()
{

}