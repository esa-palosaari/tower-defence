#include "UserGraphics.hpp"
#include <iostream>

UserGraphics::UserGraphics(Engine* engine) : engine(engine){
    
    engine->window.create(sf::VideoMode(1920, 1080), "Tower Defense Group 3", sf::Style::None);
    engine->window.setMouseCursorVisible(false);
    
    if (!Font.loadFromFile("../src/photos/FontFile.ttf")) {
        std::cout << "Can't load font" << std::endl;
    }
    
    SkipWaitingButton.setFont(Font);
    SkipWaitingButton.setString("SEND WAVE");
    SetToText(SkipWaitingButton, 1700.f, 130.f, Font, 24);
    
    PauseButton.setFont(Font);
    PauseButton.setString("OPTIONS");
    SetToText(PauseButton, 1700.f, 460.f, Font, 24);
    
    InputToName.setFont(Font);
    SetToText(InputToName, 590.f, 500.f, Font, 50);
    
    CurrentHP.setFont(Font);
    SetToText(CurrentHP, 1700.f, 650.f, Font, 24);
    
    CurrentWave.setFont(Font);
    SetToText(CurrentWave, 1700.f, 10.f, Font, 24);
    
    CurrentMoney.setFont(Font);
    SetToText(CurrentMoney, 1700.f, 50.f, Font, 24);

	CurrentScore.setFont(Font);
    SetToText(CurrentScore, 1700.f, 70.f, Font, 24);
    
    TimeToNextWave.setFont(Font);
    SetToText(TimeToNextWave, 1700.f, 90.f, Font, 24);
    
    GameOverText.setFont(Font);
    SetToText(GameOverText, 590.f, 300.f, Font, 50);
    
    PausedGameTitle.setFont(Font);
    PausedGameTitle.setString("GAME IS PAUSED");
    SetToText(PausedGameTitle, 800.f, 400.f, Font, 68);
    
    ContinueButton.setFont(Font);
    ContinueButton.setString("CONTINUE");
    SetToText(ContinueButton, 875.f, 510.f, Font, 32);
    
    SaveGameButton.setFont(Font);
    SaveGameButton.setString("SAVE GAME");
    SetToText(SaveGameButton, 888.f, 575.f, Font, 32);
    
    ExitGameButton.setFont(Font);
    ExitGameButton.setString("EXIT GAME");
    SetToText(ExitGameButton, 895.f, 640.f, Font, 32);
    
    MachinegunTowerPrice.setFont(Font);
    SetToText(MachinegunTowerPrice, 1780.f, 210.f, Font, 20);
    MachinegunTowerPrice.setString("1000");
    
    FlamethrowerTowerPrice.setFont(Font);
    SetToText(FlamethrowerTowerPrice, 1780.f, 310.f, Font, 20);
    FlamethrowerTowerPrice.setString("1000");
    
    RocketlauncherTowerPrice.setFont(Font);
    SetToText(RocketlauncherTowerPrice, 1780.f, 410.f, Font, 20);
    RocketlauncherTowerPrice.setString("1000");
    
    CircleMachinegun.setOrigin(350.f, 350.f);
    CircleMachinegun.setRadius(350.f);
    CircleMachinegun.setFillColor(sf::Color(0, 102, 102, 100));
    
    CircleFlamethrower.setOrigin(275.f, 275.f);
    CircleFlamethrower.setRadius(275.f);
    CircleFlamethrower.setFillColor(sf::Color(0, 102, 102, 100));
    
    CircleMissile.setOrigin(300.f, 300.f);
    CircleMissile.setRadius(300.f);
    CircleMissile.setFillColor(sf::Color(0, 102, 102, 100));
    
    TextureTowerMachinegun.loadFromFile("../src/photos/TowerBasicPhoto.png"); 
    TextureTowerFlameThrower.loadFromFile("../src/photos/TowerFlamePhoto.png");
    TextureTowerRocketlauncher.loadFromFile("../src/photos/TowerRocketPhoto.png");
    
    TowerMachine.setTexture(TextureTowerMachinegun);
    TowerMachine.setPosition(1740, 220);
    TowerMachine.setOrigin(32.f, 32.f);
    
    TowerFlame.setTexture(TextureTowerFlameThrower);
    TowerFlame.setPosition(1740, 320);
    TowerFlame.setOrigin(32.f, 32.f);
    
    TowerRocket.setTexture(TextureTowerRocketlauncher);
    TowerRocket.setPosition(1740, 420);
    TowerRocket.setOrigin(32.f, 32.f);
    
    TextureMouseCursor.loadFromFile("../src/photos/MouseCursorPhoto.png");
    MouseCursor.setTexture(TextureMouseCursor);
    
    TextureProjectileMachine.loadFromFile("../src/photos/TextureProjectileMachinePhoto.png");
    TextureProjectileFlame.loadFromFile("../src/photos/TextureProjectileFlamePhoto.png");
    TextureProjectileRocket.loadFromFile("../src/photos/TextureProjectileRocketPhoto.png");
    TextureAoE.loadFromFile("../src/photos/AoePhoto.png");
    TextureEnemySlow.loadFromFile("../src/photos/TextureEnemySlow.png");
    TextureEnemyMedium.loadFromFile("../src/photos/TextureEnemyMedium.png");
    TextureEnemyFast.loadFromFile("../src/photos/TextureEnemyFast.png");
    
    RedMarker.loadFromFile("../src/photos/RedMarker.png");
    CrossMarker.setTexture(RedMarker);
    CrossMarker.setScale(0.25f, 0.25f);
    
    
    Road1.setSize(sf::Vector2f(448, 192));
    Road1.setPosition(0, 64);
    
    Road2.setSize(sf::Vector2f(192, 704));
    Road2.setPosition(256, 256);
    
    Road3.setSize(sf::Vector2f(448, 192));
    Road3.setPosition(448, 768);
    
    Road4.setSize(sf::Vector2f(192, 704));
    Road4.setPosition(704, 64);
    
    Road5.setSize(sf::Vector2f(448, 192));
    Road5.setPosition(896, 64);
    
    Road6.setSize(sf::Vector2f(192, 704));
    Road6.setPosition(1152, 256);
    
    Road7.setSize(sf::Vector2f(576, 192));
    Road7.setPosition(1344, 768);
    
    MenuButton.setSize(sf::Vector2f(256, 704));		//256, 704
    MenuButton.setPosition(1664, 0);	//1664,0
    
    ScreenWhenPaused.setSize(sf::Vector2f(1920, 1080));
    ScreenWhenPaused.setFillColor(sf::Color(0, 0, 0, 150));
}

void UserGraphics::SetToText(sf::Text& textinput, float PositionX, float PositionY, sf::Font Font, int Size){
    textinput.setPosition(PositionX, PositionY);
    textinput.setCharacterSize(Size);
}

template <class t>
bool UserGraphics::insideBounds(t sprite, sf::Vector2f position){
    return sprite.getGlobalBounds().contains(position);
}

template <class t>
bool UserGraphics::insideBounds(t sprite, sf::Vector2i position){
    return sprite.getGlobalBounds().contains(position.x, position.y);
}

bool UserGraphics::OverRoad(sf::Vector2f position){
    return (insideBounds(Road1, position) || insideBounds(Road2, position) ||
            insideBounds(Road3, position) || insideBounds(Road4, position) ||
            insideBounds(Road5, position) || insideBounds(Road6, position) ||
            insideBounds(Road7, position) || insideBounds(MenuButton, position));
}

void UserGraphics::spawnTower(Types::NPC type, int MoneyLost){
    engine->spawnTower(type, sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);
    engine->loseMoney(MoneyLost);
}

void UserGraphics::manageEnd()
{
    sf::Event event;
    while (engine->window.pollEvent(event))
    {
        switch (event.type)
        {
            case(sf::Event::TextEntered):
                if (event.text.unicode == '\b' && !FinishedName)
                {
                    if (GameTag.isEmpty())
                        break;
                    else
                    {
                        GameTag.erase(GameTag.getSize() - 1, 1);
                        InputToName.setString(GameTag);
                    }
                }
                else if (event.text.unicode == '\ ')
                {
                    break;
                }
                else if (event.text.unicode == '\r')
                {
                    if (GameTag.isEmpty())
                        break;
                    else
                    {
                        FinishedName = true;
                        engine->setGameTag(GameTag);
                        InputToName.setString(GameTag + "\nPRESS ESC TO LEAVE");
                        engine->EndGame();
                    }
                }
                else if (event.text.unicode < 128 && !FinishedName && GameTag.getSize() < 16)
                {
                    GameTag.insert(GameTag.getSize(), event.text.unicode);
                    InputToName.setString(GameTag);
                }
                break;
            case(sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Escape)
                {
                    engine->window.close();
                }
        }
    }
}



void UserGraphics::managePause()
{
    sf::Event event;
    while (engine->window.pollEvent(event))
    {
        sf::Vector2i mouse(sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (ContinueButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                    engine->increaseTimeOut(TimePassedInPause.getElapsedTime().asSeconds());
                    for (auto& TWR : engine->towers)
                    {
                        TWR.setTimePause(TimePassedInPause.getElapsedTime().asMilliseconds());
                    }
                    for (auto& ENMY : engine->enemies)
                    {
                        ENMY.setTimePause(TimePassedInPause.getElapsedTime().asMilliseconds());
                    }
                    GameIsPaused = !GameIsPaused;
                }
                
                else if (ExitGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                    engine->window.close();
                }
                
                else if (SaveGameButton.getGlobalBounds().contains(mouse.x, mouse.y) && engine->isTimeOut())
                {
                    std::cout << "Type save file name:" << std::endl;
                    std::string path;
                    std::cin >> path;
                    engine->saveGame(path);
                    std::cout << "Game saved" << std::endl;
                }
            }
        }
        else if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            engine->window.close();
        }
    }
}

void UserGraphics::StartUserGraphics()
{
    while (engine->window.isOpen())
    {
        sf::Clock clock;
        sf::Time TimeSLU = sf::Time::Zero;
        while (engine->window.isOpen())
        {
            if (engine->getHP() > 0 && !GameIsPaused)
                manageEvents();
            
            TimeSLU += clock.restart();
            
            while (TimeSLU > FrameTime)
            {
                TimeSLU -= FrameTime;
                if (engine->getHP() > 0 && !GameIsPaused)
                {
                    manageEvents();
                    engine->Update(FrameTime);
                }
                else if (GameIsPaused)
                {
                    managePause();
                }
                else
                {
                    engine->Update(FrameTime);
                    manageEnd();
                }
            }
            render();
        }
    }
}

void UserGraphics::DrawMovingTower(float posx, float posy, sf::Vector2f pos)
{
    bool Drawable = true;
    
    for (auto& TWR : engine->towers)
    {
        if (TWR.tower.getGlobalBounds().contains(posx, posy))
        {
            Drawable = false;
            break;
        }
    }
    
    if (OverRoad(pos) || !Drawable)
        
    {
        InvalidPlacement = true;
        
        if (!(MenuButton.getGlobalBounds().contains(posx, posy)))
        {
            CrossMarker.setPosition(posx - 31, posy - 28);
        }
        
        else
        {
            InvalidPlacementMenu = true;
        }
    }
    
    else
    {
        ClickedTower = true;
        InvalidPlacement = false;
        InvalidPlacementMenu = false;
    }
    
    DroppedTower = false;
}


void UserGraphics::manageEvents()
{
    
    sf::Event event;
    
    while (engine->window.pollEvent(event))
    {
        
        sf::Vector2i mouse(sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);
        
        float posx = event.mouseMove.x;
        float posy = event.mouseMove.y;
        
        sf::Vector2f pos(posx, posy);
        
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            engine->window.close();
            break;
        }
        else if (event.key.code == sf::Keyboard::P && engine->isTimeOut())
        {
            engine->resetTimeOut();
        }
        
        if (event.type == sf::Event::MouseMoved)
        {
            
            if (insideBounds(TowerMachine, pos))
            {
                TowerMachine.setColor(sf::Color(0, 100, 175));
            }
            
            else
            {
                TowerMachine.setColor(sf::Color(255, 255, 255));
            }
            
           
            if (copyTowerMachinegun)
            {
                TowerMachine.setPosition(posx, posy);
                CircleMachinegun.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            }
            
            else if (copyTowerFlamethrower)
            {
                TowerFlame.setPosition(posx, posy);
                CircleFlamethrower.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            }
            
            else if (copyTowerRocketlauncher)
            {
                TowerRocket.setPosition(posx, posy);
                CircleMissile.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            }
            
            else
            {
                DroppedTower = true;
                InvalidPlacement = false;
            }
        }
        
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if ((copyTowerMachinegun || copyTowerFlamethrower || copyTowerRocketlauncher) && DroppedTower && !InvalidPlacement)
            {
                ClickedTower = true;
            }
            
            else if (InvalidPlacementMenu && copyTowerMachinegun && ClickedTower)
            {
                TowerMachine.setPosition(1740, 220);
                copyTowerMachinegun = false;
                DroppedTower = true;
                ClickedTower = false;
            }
            
            else if (InvalidPlacementMenu && copyTowerFlamethrower && ClickedTower)
            {
                TowerFlame.setPosition(1740, 320);
                copyTowerFlamethrower = false;
                DroppedTower = true;
                ClickedTower = false;
            }
            
            else if (InvalidPlacementMenu && copyTowerRocketlauncher && ClickedTower)
            {
                TowerRocket.setPosition(1740, 420);
                copyTowerRocketlauncher = false;
                DroppedTower = true;
                ClickedTower = false;
            }
            
            else
            {
                ClickedTower = false;
            }
        }
        
        if (!InvalidPlacement)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (SkipWaitingButton.getGlobalBounds().contains(mouse.x, mouse.y) && engine->isTimeOut())
                    {
                        engine->resetTimeOut();
                    }
                    else if (PauseButton.getGlobalBounds().contains(mouse.x, mouse.y))
                    {
                        TimePassedInPause.restart();
                        GameIsPaused = !GameIsPaused;
                    }
                    else if (copyTowerMachinegun && ClickedTower && !InvalidPlacementMenu)
                    {
                        spawnTower(Types::NPC::Machinegun, 1000);
                        TowerMachine.setPosition(1740, 220);
                    }
                    else if (copyTowerFlamethrower && ClickedTower && !InvalidPlacementMenu)
                    {
                        spawnTower(Types::NPC::Flamethrower, 1000);
                        TowerFlame.setPosition(1740, 320);
                    }
                    else if (copyTowerRocketlauncher && ClickedTower && !InvalidPlacementMenu)
                    {
                        spawnTower(Types::NPC::Rocketlauncher, 1000);
                        TowerRocket.setPosition(1740, 420);
                    }
                    
                    if (insideBounds(TowerMachine, mouse) && engine->getMoney() >= 1000)
                    {
                        ClickedTower = true;
                        copyTowerMachinegun = true;
                        InvalidPlacementMenu = true;
                    }
                    else if (insideBounds(TowerFlame, mouse) && engine->getMoney() >= 1000)
                    {
                       
                        ClickedTower = true;
                        copyTowerFlamethrower = true;
                        InvalidPlacementMenu = true;
                    }
                    else if (insideBounds(TowerRocket, mouse) && engine->getMoney() >= 1000)
                    {
                        ClickedTower = true;
                        copyTowerRocketlauncher = true;
                        InvalidPlacementMenu = true;
                    }
                    else
                    {
                        copyTowerMachinegun = false;
                        copyTowerFlamethrower = false;
                        copyTowerRocketlauncher = false;
                    }
                }
            }
        }
        if (InvalidPlacement)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (InvalidPlacementMenu && copyTowerMachinegun && ClickedTower)
                {
                    TowerMachine.setPosition(1740, 220);
                    copyTowerMachinegun = false;
                }
                else if (InvalidPlacementMenu && copyTowerFlamethrower && ClickedTower)
                {
                    TowerFlame.setPosition(1740, 320);
                    copyTowerFlamethrower = false;
                }
                else if (InvalidPlacementMenu && copyTowerRocketlauncher && ClickedTower)
                {
                    TowerRocket.setPosition(1740, 420);
                    copyTowerRocketlauncher = false;
                }
            }
        }
    }
}

void UserGraphics::render()
{
    engine->window.clear();
    engine->window.draw(engine->map);
    MouseCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(engine->window)));
    
    for (auto& enemy : engine->enemies)
    {
        if (!enemy.TextureInitialize)
        {
            enemy.InitializeTexture();
            if (enemy.getType() == Types::NPC::Medium)
            {
                enemy.enemy.setTexture(TextureEnemyMedium);
            }
            else if (enemy.getType() == Types::NPC::Slow)
            {
                enemy.enemy.setTexture(TextureEnemySlow);
            }
            else
            {
                enemy.enemy.setTexture(TextureEnemyFast);
            }
        }
        
        if (!enemy.CheckDead() || enemy.clock.getElapsedTime().asMilliseconds() < 1000)
        {
            engine->window.draw(enemy.enemy);
            engine->window.draw(enemy.base);
            engine->window.draw(enemy.HealthBar);
        }
    }
    
    for (auto& TWR : engine->towers)
    {
        if (!TWR.textureInitialize)
        {
            TWR.InitializeTexture();
            if (TWR.getType() == Types::NPC::Machinegun)
            {
                TWR.tower.setTexture(TextureTowerMachinegun);
            }
            else if (TWR.getType() == Types::NPC::Flamethrower)
            {
                TWR.tower.setTexture(TextureTowerFlameThrower);
            }
            else
            {
                TWR.tower.setTexture(TextureTowerRocketlauncher);
            }
        }
        engine->window.draw(TWR.getTower());
    }
    
    for (auto& projectile : engine->projectiles)
    {
        if (!projectile->textureInitialize)
        {
            projectile->InitializeTexture();
            if (projectile->getProjectileType() == Types::NPC::Machinegun)
            {
                projectile->ProjectileSprite.setTexture(TextureProjectileMachine);
            }
            else if (projectile->getProjectileType() == Types::NPC::Flamethrower)
            {
                projectile->ProjectileSprite.setTexture(TextureProjectileFlame);
            }
            else
            {
                projectile->ProjectileSprite.setTexture(TextureProjectileRocket);
            }
        }
        if (!projectile->isBlownUp())
        {
            engine->window.draw(projectile->getProjectileSprite());  
        }
        
        if (projectile->GraphArea)
        {
            projectile->AoE.setTexture(TextureAoE);
            engine->window.draw(projectile->AoE);
        }
        
    }
    CurrentHP.setString("HP: " + std::to_string(engine->getHP()));
    CurrentWave.setString("Wave: " + std::to_string(engine->getLevel()));
    CurrentMoney.setString("Money: " + std::to_string(engine->getMoney()));
	CurrentScore.setString("Score: "+std::to_string(engine->getScore()));
    
    engine->window.draw(CurrentHP);
    engine->window.draw(CurrentWave);
    engine->window.draw(CurrentMoney);
	engine->window.draw(CurrentScore);
    engine->window.draw(PauseButton);
    if (engine->isTimeOut())
    {
        engine->window.draw(SkipWaitingButton);
    }
    
    if (engine->getMoney() < 100)
    {
        TowerMachine.setColor(sf::Color(128, 128, 128));
    }
    
    else
    {
        TowerMachine.setColor(sf::Color(255, 255, 255));
    }
    
    if (engine->getMoney() < 100)
    {
        TowerFlame.setColor(sf::Color(128, 128, 128));
    }
    
    else
    {
        TowerFlame.setColor(sf::Color(255, 255, 255));
    }
    
    if (engine->getMoney() < 100)
    {
        TowerRocket.setColor(sf::Color(128, 128, 128));
    }
    
    else
    {
        TowerRocket.setColor(sf::Color(255, 255, 255));
    }
    
    if (copyTowerMachinegun && !DroppedTower)
    {
        engine->window.draw(CircleMachinegun);
    }
    
    else if (copyTowerFlamethrower && !DroppedTower)
    {
        engine->window.draw(CircleFlamethrower);
    }
    
    else if (copyTowerRocketlauncher && !DroppedTower)
    {
        engine->window.draw(CircleMissile);
    }
    engine->window.draw(TowerMachine);
    engine->window.draw(TowerFlame);
    engine->window.draw(TowerRocket);
    
    engine->window.draw(MachinegunTowerPrice);
    engine->window.draw(FlamethrowerTowerPrice);
    engine->window.draw(RocketlauncherTowerPrice);
    
    if (InvalidPlacement && !InvalidPlacementMenu)
    {
        engine->window.draw(CrossMarker);
        InvalidPlacementMenu = false;
    }
    
    if (engine->isTimeOut() && !GameIsPaused)
    {
        TimeToNextWave.setString("Next wave in: " + std::to_string(engine->TimeToNextRound()));
    }
    else
    {
        TimeToNextWave.setString("INCOMING!");
    }
    engine->window.draw(TimeToNextWave);
    
    if (engine->getHP() <= 0)
    {
        GameOverText.setString("GET REKT NOOB!\nWAVES SURVIVED: " + std::to_string(engine->getLevel()) + "\nTOTAL SCORE: " + std::to_string(engine->getScore()) + "\nPLAYER NAME: ");
        engine->window.draw(InputToName);
        engine->window.draw(GameOverText);
    }
    
    if (GameIsPaused)
    {
        engine->window.draw(ScreenWhenPaused);
        engine->window.draw(PausedGameTitle);
        engine->window.draw(ContinueButton);
        engine->window.draw(ExitGameButton);
        engine->window.draw(SaveGameButton);
    }
    
    engine->window.draw(MouseCursor);
    
    engine->window.display();
}

