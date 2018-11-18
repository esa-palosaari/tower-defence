#ifndef UserGraphics_hpp
#define UserGraphics_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Tilemap.hpp"
#include "Enemy.hpp"
#include "Engine.hpp"

class UserGraphics
{
public:
    UserGraphics(Engine* engine);
    void StartUserGraphics();
    void SetToText(sf::Text& text, float x, float y, sf::Font font, int size);
    void render();
    void manageEvents();
    void manageEnd();
    void managePause();
    
    template <class t>
    bool insideBounds(t sprite, sf::Vector2f pos);
    template <class t>
    bool insideBounds(t sprite, sf::Vector2i pos);
    template <class t, class y>
    bool insideBounds(t sprite, y pos);
    
    bool OverRoad(sf::Vector2f pos);
    void spawnTower(Types::NPC type, int losePoints);
    void DrawMovingTower(float posx, float posy, sf::Vector2f pos);
    
    void Update(sf::Time elapsedTime);
    
private:
    Engine* engine;
    std::vector<sf::Sprite> towers;
    bool FinishedName = false;
    bool copyTowerMachinegun = false;
    bool copyTowerFlamethrower = false;
    bool copyTowerRocketlauncher = false;
    bool ClickedTower = false;
    bool DroppedTower = false;
    bool topScoresInit = false;
    bool InvalidPlacement = true;
    bool InvalidPlacementMenu = true;
    bool GameIsPaused = false;
    
    const sf::Time FrameTime = sf::seconds(1.f / 60.f);
    
    sf::Clock TimePassedInPause;
    sf::Texture TextureProjectileMachine;
    sf::Texture TextureProjectileFlame;
    sf::Texture TextureProjectileRocket;
    sf::Texture TextureEnemySlow
    sf::Texture TextureEnemyMedium;
    sf::Texture TextureEnemyFast;
    sf::Texture TextureTowerMachinegun;
    sf::Texture TextureTowerFlameThrower;
    sf::Texture TextureTowerRocketlauncher;
    sf::Texture TextureAoE;
    sf::Texture TextureMouseCursor;
    sf::Texture RedMarker;
    sf::Texture TextureTowerPlatform;
    sf::Sprite MouseCursor;
    sf::Sprite TowerMachine;
    sf::Sprite TowerFlame;
    sf::Sprite TowerRocket;
    sf::Sprite CrossMarker;
    sf::CircleShape CircleMachinegun;
    sf::CircleShape CircleFlamethrower;
    sf::CircleShape CircleMissile;
    sf::RectangleShape Road1;
    sf::RectangleShape Road2;
    sf::RectangleShape Road3;
    sf::RectangleShape Road4;
    sf::RectangleShape Road5;
    sf::RectangleShape Road6;
    sf::RectangleShape Road7;
    sf::RectangleShape MenuButton;
    sf::RectangleShape ScreenWhenPaused;
    sf::Font Font;
    sf::String GameTag;
    sf::Text SkipWaitingButton;
    sf::Text PauseButton;
    sf::Text PausedGameTitle;
    sf::Text ContinueButton;
    sf::Text ExitGameButton;
    sf::Text SaveGameButton;
    sf::Text InputToName;
    sf::Text GameOverText;
    sf::Text CurrentHP;
    sf::Text CurrentWave;
    sf::Text CurrentMoney;
    sf::Text TimeToNextWave;
    sf::Text MachinegunTowerPrice;
    sf::Text FlamethrowerTowerPrice;
    sf::Text RocketlauncherTowerPrice;
};

#endif

