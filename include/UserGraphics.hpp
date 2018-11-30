#ifndef UserGraphics_hpp
#define UserGraphics_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
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
	void setUpgradeButtonColor(float PositionX, float PositionY, std::vector<Tower>::value_type& tower);
	bool upgradePressed(sf::Vector2i mouse, std::vector<Tower>::value_type& tower);
	bool canUpgrade(sf::Vector2i position, Tower& tower);
    
    void Update(sf::Time elapsedTime);
	void showHiscores();
    
private:
    Engine* engine;
    std::vector<sf::Sprite> towers;
	std::vector<sf::Text> topScores;
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
	bool UpgradeClick=false;
	bool CannotUpgrade=false;
	
    
    const sf::Time FrameTime = sf::seconds(1.f / 60.f);

	std::string UpgradePrice;
    
    sf::Clock TimePassedInPause;
    sf::Texture TextureProjectileMachine;
    sf::Texture TextureProjectileFlame;
    sf::Texture TextureProjectileRocket;
    sf::Texture TextureEnemySlow;
    sf::Texture TextureEnemyMedium;
    sf::Texture TextureEnemyFast;
	sf::Texture TextureEnemyCommander;
	sf::Texture TextureEnemyKiller;
	sf::Texture TextureEnemyAircraft;
    sf::Texture TextureTowerMachinegun;
    sf::Texture TextureTowerFlameThrower;
    sf::Texture TextureTowerRocketlauncher;
    sf::Texture TextureAoE;
    sf::Texture TextureMouseCursor;
    sf::Texture RedMarker;
    sf::Texture TextureTowerPlatform;
	sf::Texture TextureInfoPanel;
	sf::Texture TextureInfoPanelMG;
	sf::Texture TextureInfoPanelFT;
	sf::Texture TextureInfoPanelRL;
	sf::Sprite IPMG;
	sf::Sprite IPFT;
	sf::Sprite IPRL;
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
	sf::RectangleShape UpgradeButton;
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
	sf::Text CurrentScore;
    sf::Text TimeToNextWave;
    sf::Text MachinegunTowerPrice;
    sf::Text FlamethrowerTowerPrice;
    sf::Text RocketlauncherTowerPrice;
	sf::Text infoText1;
	sf::Text infoText2;
	sf::Text infoText3;
	sf::Text infotextDMG;
	sf::Text infotextFirerate;
	sf::Text infotextRange;
	sf::Text infotextHL;
	sf::Text LevelUpgrade;
	sf::Text TowerArsenal;
	sf::Text TopScoreHL;

};

#endif

