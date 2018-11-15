#ifndef Types_hpp
#define Types_hpp

class Types
{
    public:
        enum NPC
        {
            Machinegun, // High fire rate, low damage. Impact damage on single target.
            Flame, // Medium fire rate, medium damage. Possible ray effect.
            Launcher, // Low fire rate, high damage. AoE.
            Slow, // Slow speed, high HP. "Tank"
            Medium, // Medium speed, medium HP. "Pasi"
            Fast, // High speed, low HP. "Bike"
            Bullet, // Projectile type 1
            Flame, // Projectile type 2
            Rocket // Projectile type 3
        };

};
#endif