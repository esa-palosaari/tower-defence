#include "Projectile.hpp"
#include "Engine.hpp"
#include <memory> // tarvitaanko tata?
#include <vector>

Projectile::Projectile(Engine* game, Types::NPC type, int x, int y) : game(game), type(type), x(x), y(y)
{
    switch (type)
    {
        case(Types::NPC::type_7): // korjaa type ja arvot oikeaksi
        int DMG = 100;
        // tarvitaanko muita muuttujia?
        break;
    
        case(Types::NPC::type_8):
        int DMG = 200;
        break;

        case(Types::NPC::type_9):
        int DMG = 300;
        break;
    }
}

// implementoi funktiot
void Projectile::move()
{

}
void Projectile::hit()
{

}
void Projectile::checkGoal()
{

}
