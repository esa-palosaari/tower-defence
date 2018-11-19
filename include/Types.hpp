#ifndef Types_hpp
#define Types_hpp

class Types
{
    public:
        enum NPC
        {
            Machinegun, // High fire rate, low damage. Impact damage on single target.
            Flamethrower, // Medium fire rate, medium damage. Possible ray effect.
            Rocketlauncher, // Low fire rate, high damage. AoE.
            Slow, // Slow speed, high HP. "Tank"
            Medium, // Medium speed, medium HP. "Pasi"
            Fast, // High speed, low HP. "Bike"
        };

};
#endif