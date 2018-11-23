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
		Commander, //Boss type. Each wave has its own commander. Honorable man who leads with example.
		Killer, //This one is a tough bastard. We pray for your souls.
        };

};
#endif
