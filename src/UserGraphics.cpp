#include "UserGraphics.hpp"
#include <iostream>
#include <math.h>

UserGraphics::UserGraphics(Engine* engine) : engine(engine){

    engine->window.create(sf::VideoMode(1920, 1080), "Tower Defense Group 3", sf::Style::None);
    engine->window.setMouseCursorVisible(false);

    if (!Font.loadFromFile("../src/photos/FontFile.ttf")) {
        std::cout << "Can't load font" << std::endl;
    }

    SkipWaitingButton.setFont(Font);
    SkipWaitingButton.setString("SEND WAVE");
    SetToText(SkipWaitingButton, 1680.f, 125.f, Font, 24);

  	TopScoreHL.setFont(Font);
  	TopScoreHL.setString("TOP 10 PLAYERS:");
  	SetToText(TopScoreHL,10.f,10.f,Font,40);

    PauseButton.setFont(Font);
    PauseButton.setString("OPTIONS");
    SetToText(PauseButton, 1680.f, 460.f, Font, 24);

  	TowerArsenal.setFont(Font);
  	TowerArsenal.setString("TOWERS:");
  	SetToText(TowerArsenal, 1680.f, 155.f, Font, 24);

    InputToName.setFont(Font);
    SetToText(InputToName, 590.f, 500.f, Font, 50);

    CurrentHP.setFont(Font);
    SetToText(CurrentHP, 1680.f, 667.f, Font, 24);

    CurrentWave.setFont(Font);
    SetToText(CurrentWave, 1680.f, 10.f, Font, 24);

    CurrentMoney.setFont(Font);
    SetToText(CurrentMoney, 1680.f, 40.f, Font, 24);

	CurrentScore.setFont(Font);
    SetToText(CurrentScore, 1680.f, 65.f, Font, 24);

    TimeToNextWave.setFont(Font);
    SetToText(TimeToNextWave, 1680.f, 90.f, Font, 24);

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
    SetToText(ExitGameButton, 888.f, 575.f, Font, 32);

    MachinegunTowerPrice.setFont(Font);
    SetToText(MachinegunTowerPrice, 1740.f, 210.f, Font, 20);
    MachinegunTowerPrice.setString("500");

    FlamethrowerTowerPrice.setFont(Font);
    SetToText(FlamethrowerTowerPrice, 1740.f, 310.f, Font, 20);
    FlamethrowerTowerPrice.setString("500");

    RocketlauncherTowerPrice.setFont(Font);
    SetToText(RocketlauncherTowerPrice, 1740.f, 410.f, Font, 20);
    RocketlauncherTowerPrice.setString("500");

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
    TowerMachine.setPosition(1700, 220);
    TowerMachine.setOrigin(32.f, 32.f);

    TowerFlame.setTexture(TextureTowerFlameThrower);
    TowerFlame.setPosition(1700, 320);
    TowerFlame.setOrigin(32.f, 32.f);

    TowerRocket.setTexture(TextureTowerRocketlauncher);
    TowerRocket.setPosition(1700, 420);
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
  	TextureEnemyCommander.loadFromFile("../src/photos/TextureEnemyCommander.png");
  	TextureEnemyKiller.loadFromFile("../src/photos/TextureEnemyKiller.png");
  	TextureEnemyAircraft.loadFromFile("../src/photos/TextureEnemyAircraft.png");

    RedMarker.loadFromFile("../src/photos/RedMarker.png");
    CrossMarker.setTexture(RedMarker);
    CrossMarker.setScale(0.25f, 0.25f);

  	TextureInfoPanel.loadFromFile("../src/photos/InfoPanel.png");

  	TextureInfoPanelMG.loadFromFile("../src/photos/InfoPanel.png");
  	TextureInfoPanelFT.loadFromFile("../src/photos/InfoPanel.png");
  	TextureInfoPanelRL.loadFromFile("../src/photos/InfoPanel.png");

  	IPMG.setTexture(TextureInfoPanelMG);
  	IPMG.setPosition(1670, 185);
  	IPMG.setScale(0.4f, 0.15f);

  	IPFT.setTexture(TextureInfoPanelMG);
  	IPFT.setPosition(1670, 285);
  	IPFT.setScale(0.4f, 0.15f);


  	IPRL.setTexture(TextureInfoPanelMG);
  	IPRL.setPosition(1670, 385);
  	IPRL.setScale(0.4f, 0.15f);


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

    MenuButton.setSize(sf::Vector2f(256, 704));
    MenuButton.setPosition(1664, 0);

    ScreenWhenPaused.setSize(sf::Vector2f(1920, 1080));
    ScreenWhenPaused.setFillColor(sf::Color(0, 0, 0, 150));

  	UpgradeButton.setSize(sf::Vector2f(210,45));
  	UpgradeButton.setPosition(1690,495);
  	UpgradeButton.setFillColor(sf::Color(102,204,0));

	infoText1.setFont(Font);
	infoText1.setPosition(1710,550);
	infoText1.setCharacterSize(18);

	infoText2.setFont(Font);
	infoText2.setPosition(1710,540);
	infoText2.setCharacterSize(20);

	infoText3.setFont(Font);
	infoText3.setPosition(1720,650);
	infoText3.setCharacterSize(13);

	infotextHL.setFont(Font);
	infotextHL.setPosition(1715,570);
	infotextHL.setCharacterSize(14);

	infotextDMG.setFont(Font);
	infotextDMG.setPosition(1720,590);
	infotextDMG.setCharacterSize(14);

	infotextFirerate.setFont(Font);
	infotextFirerate.setPosition(1720,610);
	infotextFirerate.setCharacterSize(14);

	infotextRange.setFont(Font);
	infotextRange.setPosition(1720,630);
	infotextRange.setCharacterSize(14);

	LevelUpgrade.setFont(Font);
	LevelUpgrade.setPosition(1700.f,505.f);
	LevelUpgrade.setCharacterSize(20);


	MachinegunSound.loadFromFile("../src/sounds/MG.ogg");
	FlamerSound.loadFromFile("../src/sounds/FT.wav");
	RocketSound.loadFromFile("../src/sounds/ML.ogg");
	ExplosionSound.loadFromFile("../src/sounds/explosion.ogg");
	UpgradeSound.loadFromFile("../src/sounds/upgrade.wav");
	Click.loadFromFile("../src/sounds/click.ogg");
	ClickSound.setBuffer(Click);

}

void UserGraphics::SetToText(sf::Text& textinput, float PositionX, float PositionY, sf::Font Font, int Size){
    textinput.setPosition(PositionX, PositionY);
    textinput.setCharacterSize(Size);
}


// Template functions to check whether object is inside bounds

template <class t>
bool UserGraphics::insideBounds(t sprite, sf::Vector2f position){
    return sprite.getGlobalBounds().contains(position);
}

template <class t>
bool UserGraphics::insideBounds(t sprite, sf::Vector2i position){
    return sprite.getGlobalBounds().contains(position.x, position.y);
}

// Checks if road vectors are inside bounds
bool UserGraphics::OverRoad(sf::Vector2f position){
    return (insideBounds(Road1, position) || insideBounds(Road2, position) ||
            insideBounds(Road3, position) || insideBounds(Road4, position) ||
            insideBounds(Road5, position) || insideBounds(Road6, position) ||
            insideBounds(Road7, position) || insideBounds(MenuButton, position));
}

// Set upgrade button color
void UserGraphics::setUpgradeButtonColor(float PositionX, float PositionY, std::vector<Tower>::value_type& tower){
	if(tower.UpgradeClick){
		if(UpgradeButton.getGlobalBounds().contains(PositionX, PositionY) || !tower.UpgradeLevel){
			UpgradeButton.setFillColor(sf::Color(160, 160, 160));
		} else {
			UpgradeButton.setFillColor(sf::Color(102, 204, 0));
		}
	}
}

// Checks if upgrade button is pressed
bool UserGraphics::upgradePressed(sf::Vector2i mouse, std::vector<Tower>::value_type& tower){
	if(tower.UpgradeClick && UpgradeButton.getGlobalBounds().contains(mouse.x, mouse.y)){
		UpgradeClick = true;
		if(UpgradeButton.getGlobalBounds().contains(mouse.x, mouse.y)){
			tower.setTowerLevel();
			UpgradeButton.setFillColor(sf::Color(102,204,0));
			return true;
		}
	} else {
		UpgradeClick = false;
		return false;
	}
	return false;
}

// Checks if tower can be upgraded
bool UserGraphics::canUpgrade(sf::Vector2i position, Tower& tower){
	if(tower.getTowerLevel() != 4){
		if(tower.UpgradeClick && UpgradeButton.getGlobalBounds().contains(position.x, position.y)){
			if(engine->getMoney() < (tower.getTowerLevel() *200)){
				UpgradeButton.setFillColor(sf::Color(160,160,160));
				tower.UpgradeLevel = false;
				CannotUpgrade = true;
				return false;
			} else {
				UpgradeButton.setFillColor(sf::Color(102,204,0));
				tower.UpgradeLevel=true;
				CannotUpgrade=false;
				return true;
			}
			if(!CannotUpgrade){
				UpgradeButton.setFillColor(sf::Color(102,204,0));
				tower.UpgradeLevel = true;
				CannotUpgrade = false;
				return true;
			}
		}
		else if(insideBounds(tower.tower, position)){
			tower.UpgradeClick = true;
			UpgradeClick = true;
			if(engine->getMoney() < (tower.getTowerLevel() *200)){
				UpgradeButton.setFillColor(sf::Color(160,160,160));
				tower.UpgradeLevel = false;
				CannotUpgrade = true;
				return	false;
			}
			else{
				UpgradeButton.setFillColor(sf::Color(102,204,0));
				tower.UpgradeLevel = true;
				CannotUpgrade = false;
				return true;
			}
			if(!CannotUpgrade){
				UpgradeButton.setFillColor(sf::Color(102,204,0));
				tower.UpgradeLevel = true;
				CannotUpgrade = false;
				return true;
			}
		}
		else{
			tower.UpgradeClick = false;
			UpgradeClick = false;
			return false;
		}
	}
	else{
		if(tower.UpgradeClick && UpgradeButton.getGlobalBounds().contains(position.x, position.y)){
			UpgradeButton.setFillColor(sf::Color(160,160,160));
			tower.UpgradeLevel = false;
			CannotUpgrade=true;
			return false;
		}
		else if(insideBounds(tower.tower, position)){
			tower.UpgradeClick=true;
			UpgradeClick=true;
			UpgradeButton.setFillColor(sf::Color(160,160,160));
			tower.UpgradeLevel=false;
			CannotUpgrade=true;
			return	false;
		}
		else{
			tower.UpgradeClick=false;
			UpgradeClick=false;
			return false;
		}

	}
	return false;
}


// Shows game's high scores
void UserGraphics::showHiscores(){
	if(engine->showTopScore()){
		if(!topScoresInit){
			topScoresInit = true;
			float y = 70.f;
			int i = 1;
			for(auto& score : engine->topScoresVec){
				sf::Text temp;
				temp.setFont(Font);
				temp.setCharacterSize(20);
				temp.setPosition(20.f, y);
				temp.setString(std::to_string(i) + ". " + score.name + " - Score: " + std::to_string(score.score));
				topScores.push_back(temp);
				y += 50.f;
				i++;
				if(i == 11){
					break;
				}
			}
		}
		for(auto& text : topScores){
			text.setPosition(text.getPosition().x, text.getPosition().y);
		}
	}
}

// Spawns new towers
void UserGraphics::spawnTower(Types::NPC type, int MoneyLost){
    engine->spawnTower(type, sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);
    engine->loseMoney(MoneyLost);
}

// Ends the game, manages events
void UserGraphics::manageEnd(){
    sf::Event event;
    while (engine->window.pollEvent(event)){
        switch (event.type){
            case(sf::Event::TextEntered):
                if (event.text.unicode == '\b' && !FinishedName){
                    if (GameTag.isEmpty()) {
                        break;
                    } else {
                        GameTag.erase(GameTag.getSize() - 1, 1);
                        InputToName.setString(GameTag);
                    }
                } else if (event.text.unicode == '\r') {
                    if (GameTag.isEmpty()) {
                        break;
                    } else {
                        FinishedName = true;
                        engine->setGameTag(GameTag);
                        InputToName.setString(GameTag + "\nPRESS ESC TO LEAVE");
                        engine->EndGame();
                    }
                } else if (event.text.unicode < 128 && !FinishedName && GameTag.getSize() < 16) {
                    GameTag.insert(GameTag.getSize(), event.text.unicode);
                    InputToName.setString(GameTag);
                }

                break;

            case(sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Escape) {
                    engine->window.close();
                }
        }
    }
}


// Manages pause state
void UserGraphics::managePause() {
    sf::Event event;
    while (engine->window.pollEvent(event)) {
        sf::Vector2i mouse(sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);
        if (event.type == sf::Event::MouseButtonPressed){
			      ClickSound.play();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if (ContinueButton.getGlobalBounds().contains(mouse.x, mouse.y)){
                    engine->increaseTimeOut(TimePassedInPause.getElapsedTime().asSeconds());
                    for (auto& TWR : engine->towers){
                        TWR.setTimePause(TimePassedInPause.getElapsedTime().asMilliseconds());
                    }
                    for (auto& ENMY : engine->enemies){
                        ENMY.setTimePause(TimePassedInPause.getElapsedTime().asMilliseconds());
                    }

                    GameIsPaused = !GameIsPaused;
                } else if (ExitGameButton.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    engine->window.close();
                } 
            }

        } else if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            engine->window.close();
        }
    }
}

// Starts the UserGraphics
void UserGraphics::StartUserGraphics(){
    while (engine->window.isOpen()){
        sf::Clock clock;
        sf::Time TimeSLU = sf::Time::Zero;
        while (engine->window.isOpen()){
            if (engine->getHP() > 0 && !GameIsPaused)
                manageEvents();

            TimeSLU += clock.restart();

            while (TimeSLU > FrameTime){
                TimeSLU -= FrameTime;
                if (engine->getHP() > 0 && !GameIsPaused) {
                    manageEvents();
                    engine->Update(FrameTime);
                } else if (GameIsPaused) {
                    managePause();
                } else {
                    engine->Update(FrameTime);
                    manageEnd();
              			if(engine->isEnd()){
              				showHiscores();
              			}
                }
            }
            render();
        }
    }
}

// Draws moving towers
void UserGraphics::DrawMovingTower(float posx, float posy, sf::Vector2f pos) {
    bool Drawable = true;
    for (auto& TWR : engine->towers) {
        if (TWR.tower.getGlobalBounds().contains(posx, posy)){
            Drawable = false;
            break;
        }
    }

    if (OverRoad(pos) || !Drawable) {
        InvalidPlacement = true;

        if (!(MenuButton.getGlobalBounds().contains(posx, posy))){
            CrossMarker.setPosition(posx - 31, posy - 28);
        } else {
            InvalidPlacementMenu = true;
        }
    } else {
        ClickedTower = true;
        InvalidPlacement = false;
        InvalidPlacementMenu = false;
    }

    DroppedTower = false;
}

// Manages events such as mouse clicks during the game
void UserGraphics::manageEvents() {

    sf::Event event;
    while (engine->window.pollEvent(event)) {

        sf::Vector2i mouse(sf::Mouse::getPosition(engine->window).x, sf::Mouse::getPosition(engine->window).y);

        float posx = event.mouseMove.x;
        float posy = event.mouseMove.y;

        sf::Vector2f pos(posx, posy);

        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            engine->window.close();
            break;
        } else if (event.key.code == sf::Keyboard::P && engine->isTimeOut()) {
            engine->resetTimeOut();
        }

        if (event.type == sf::Event::MouseMoved) {
            if (insideBounds(TowerMachine, pos)) {
                TowerMachine.setColor(sf::Color(0, 100, 175));
            } else {
                TowerMachine.setColor(sf::Color(255, 255, 255));
            }

            for(auto& tower : engine->towers){
			          setUpgradeButtonColor(posx, posy, tower);
		         }

            if (copyTowerMachinegun) {
                TowerMachine.setPosition(posx, posy);
                CircleMachinegun.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            } else if (copyTowerFlamethrower) {
                TowerFlame.setPosition(posx, posy);
                CircleFlamethrower.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            } else if (copyTowerRocketlauncher) {
                TowerRocket.setPosition(posx, posy);
                CircleMissile.setPosition(posx, posy);
                DrawMovingTower(posx, posy, pos);
            } else {
                DroppedTower = true;
                InvalidPlacement = false;
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if ((copyTowerMachinegun || copyTowerFlamethrower || copyTowerRocketlauncher) && DroppedTower && !InvalidPlacement){
                ClickedTower = true;
            } else if (InvalidPlacementMenu && copyTowerMachinegun && ClickedTower) {
                TowerMachine.setPosition(1700, 220);
                copyTowerMachinegun = false;
                DroppedTower = true;
                ClickedTower = false;
            } else if (InvalidPlacementMenu && copyTowerFlamethrower && ClickedTower) {
                TowerFlame.setPosition(1700, 320);
                copyTowerFlamethrower = false;
                DroppedTower = true;
                ClickedTower = false;
            } else if (InvalidPlacementMenu && copyTowerRocketlauncher && ClickedTower) {
                TowerRocket.setPosition(1700, 420);
                copyTowerRocketlauncher = false;
                DroppedTower = true;
                ClickedTower = false;
            } else {
                ClickedTower = false;
            }
        }

        if (!InvalidPlacement) {
            if (event.type == sf::Event::MouseButtonPressed) {
				        ClickSound.play();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (SkipWaitingButton.getGlobalBounds().contains(mouse.x, mouse.y) && engine->isTimeOut()) {
                        engine->resetTimeOut();
                    } else if (PauseButton.getGlobalBounds().contains(mouse.x, mouse.y)) {
                        TimePassedInPause.restart();
                        GameIsPaused = !GameIsPaused;
                    } else if (copyTowerMachinegun && ClickedTower && !InvalidPlacementMenu) {
                        spawnTower(Types::NPC::Machinegun, 500);
                        TowerMachine.setPosition(1700, 220);
                    } else if (copyTowerFlamethrower && ClickedTower && !InvalidPlacementMenu) {
                        spawnTower(Types::NPC::Flamethrower, 500);
                        TowerFlame.setPosition(1700, 320);
                    } else if (copyTowerRocketlauncher && ClickedTower && !InvalidPlacementMenu) {
                        spawnTower(Types::NPC::Rocketlauncher, 500);
                        TowerRocket.setPosition(1700, 420);
                    }

                    if (insideBounds(TowerMachine, mouse) && engine->getMoney() >= 500) {
                        ClickedTower = true;
                        copyTowerMachinegun = true;
                        InvalidPlacementMenu = true;
                    } else if (insideBounds(TowerFlame, mouse) && engine->getMoney() >= 500) {
                        ClickedTower = true;
                        copyTowerFlamethrower = true;
                        InvalidPlacementMenu = true;
                    } else if (insideBounds(TowerRocket, mouse) && engine->getMoney() >= 500) {
                        ClickedTower = true;
                        copyTowerRocketlauncher = true;
                        InvalidPlacementMenu = true;
                    } else {
                        copyTowerMachinegun = false;
                        copyTowerFlamethrower = false;
                        copyTowerRocketlauncher = false;
                    }

            			for(auto& tower : engine->towers){
            				if(canUpgrade(mouse, tower)){
            					if(upgradePressed(mouse, tower)){
            						break;
            					}
            				}
            			}
                }
            }
        }


        if (InvalidPlacement) {
            if (event.type == sf::Event::MouseButtonPressed){
				          ClickSound.play();
				          if (InvalidPlacementMenu && copyTowerMachinegun && ClickedTower) {
                    TowerMachine.setPosition(1700, 220);
                    copyTowerMachinegun = false;
                } else if (InvalidPlacementMenu && copyTowerFlamethrower && ClickedTower) {
                    TowerFlame.setPosition(1700, 320);
                    copyTowerFlamethrower = false;
                } else if (InvalidPlacementMenu && copyTowerRocketlauncher && ClickedTower) {
                    TowerRocket.setPosition(1700, 420);
                    copyTowerRocketlauncher = false;
                }
            }
        }
    }
}


// Renders the game window
void UserGraphics::render() {

    engine->window.clear();
    engine->window.draw(engine->map);
    MouseCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(engine->window)));

    // Sets textures for enemies
    for (auto& enemy : engine->enemies) {
        if (!enemy.TextureInitialize) {
            enemy.InitializeTexture();
            if (enemy.getType() == Types::NPC::Medium) {
                enemy.enemy.setTexture(TextureEnemyMedium);
            } else if (enemy.getType() == Types::NPC::Slow) {
                enemy.enemy.setTexture(TextureEnemySlow);
            } else if(enemy.getType()==Types::NPC::Fast) {
                enemy.enemy.setTexture(TextureEnemyFast);
            } else if(enemy.getType()==Types::NPC::Commander){
			         enemy.enemy.setTexture(TextureEnemyCommander);
		        } else if(enemy.getType()==Types::NPC::Aircraft){
			         enemy.enemy.setTexture(TextureEnemyAircraft);
		        } else {
			        enemy.enemy.setTexture(TextureEnemyKiller);
		        }
      }

        if (!enemy.CheckDead() || enemy.clock.getElapsedTime().asMilliseconds() < 1000) {
            engine->window.draw(enemy.enemy);
            engine->window.draw(enemy.base);
            engine->window.draw(enemy.HealthBar);
        }
    }

    // Sets textures for towers
    for (auto& TWR : engine->towers) {
        if (!TWR.textureInitialize) {
            TWR.InitializeTexture();
            if (TWR.getType() == Types::NPC::Machinegun) {
                TWR.tower.setTexture(TextureTowerMachinegun);
				        TWR.shootSound.setBuffer(MachinegunSound);
            } else if (TWR.getType() == Types::NPC::Flamethrower) {
                TWR.tower.setTexture(TextureTowerFlameThrower);
				        TWR.shootSound.setBuffer(FlamerSound); // replace!!!
            } else {
                TWR.tower.setTexture(TextureTowerRocketlauncher);
				        TWR.shootSound.setBuffer(RocketSound); // replace!!!
            }
        }

       // Infopanel for tower textures
	     if(TWR.UpgradeClick || UpgradeClick){
        		TWR.infopanel.setTexture(TextureInfoPanel);
        		engine->window.draw(TWR.infopanel);
        		infoText2.setString("Upgrade Tower");
        		infoText3.setString("LEVEL - " + std::to_string(TWR.getTowerLevel()));
        		infotextDMG.setString("Damage: " + std::to_string(TWR.getDMG()));
        		infotextFirerate.setString("Firerate: " + std::to_string(TWR.getFirerate()));
        		infotextRange.setString("Range: " + std::to_string(TWR.getRange()));
        		infotextHL.setString("Statistics:");
        		if(TWR.getType() == Types::NPC::Machinegun){
        			infoText1.setString("Machinegun");
        			UpgradePrice=std::to_string((int)(pow(2,TWR.getTowerLevel()-1)*200));
        			if(UpgradePrice == "1600"){
        				UpgradePrice = "MAX LEVEL";
        				LevelUpgrade.setString(UpgradePrice);
        			} else {
        				LevelUpgrade.setString(UpgradePrice+"$ UPGRADE");
        			}
        		} else if(TWR.getType() == Types::NPC::Flamethrower){
          			infoText1.setString("Flamethrower");
          			UpgradePrice=std::to_string((int)(pow(2,TWR.getTowerLevel()-1)*200));
          			if(UpgradePrice=="1600"){
          				UpgradePrice="MAX LEVEL";
          				LevelUpgrade.setString(UpgradePrice);
          			} else {
          				LevelUpgrade.setString(UpgradePrice+"$ UPGRADE");
          			}
        		} else {
        			infoText1.setString("Rocketlauncher");
        			UpgradePrice=std::to_string((int)(pow(2,TWR.getTowerLevel()-1)*200));
        			if(UpgradePrice == "1600"){
        				UpgradePrice="MAX LEVEL";
        				LevelUpgrade.setString(UpgradePrice);
        			} else {
        				LevelUpgrade.setString(UpgradePrice+"$ UPGRADE");
        			}
        		}

        		engine->window.draw(UpgradeButton);
        		engine->window.draw(LevelUpgrade);
        		engine->window.draw(infoText1);
        		engine->window.draw(infoText3);
        		engine->window.draw(infotextDMG);
        		engine->window.draw(infotextFirerate);
        		engine->window.draw(infotextRange);
        		engine->window.draw(infotextHL);

	    }
        engine->window.draw(TWR.getTower());
  }
  // Textures for projectiles
    for (auto& projectile : engine->projectiles) {
        if (!projectile->textureInitialize) {
            projectile->InitializeTexture();
            if (projectile->getProjectileType() == Types::NPC::Machinegun) {
                projectile->ProjectileSprite.setTexture(TextureProjectileMachine);
            } else if (projectile->getProjectileType() == Types::NPC::Flamethrower) {
                projectile->ProjectileSprite.setTexture(TextureProjectileFlame);
            } else {
                projectile->ProjectileSprite.setTexture(TextureProjectileRocket);
            }
        }
        if (!projectile->isBlownUp()) {
            engine->window.draw(projectile->getProjectileSprite());
        }

        if (projectile->GraphArea) {
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
	  engine->window.draw(TowerArsenal);

    if (engine->isTimeOut()) {
        engine->window.draw(SkipWaitingButton);
    }

    if (engine->getMoney() < 500) {
        TowerMachine.setColor(sf::Color(128, 128, 128));
    } else {
        TowerMachine.setColor(sf::Color(255, 255, 255));
    }

    if (engine->getMoney() < 500) {
        TowerFlame.setColor(sf::Color(128, 128, 128));
    } else {
        TowerFlame.setColor(sf::Color(255, 255, 255));
    }

    if (engine->getMoney() < 500) {
        TowerRocket.setColor(sf::Color(128, 128, 128));
    } else {
        TowerRocket.setColor(sf::Color(255, 255, 255));
    }

    if (copyTowerMachinegun && !DroppedTower) {
        engine->window.draw(CircleMachinegun);
    } else if (copyTowerFlamethrower && !DroppedTower) {
        engine->window.draw(CircleFlamethrower);
    } else if (copyTowerRocketlauncher && !DroppedTower) {
        engine->window.draw(CircleMissile);
    }

  	engine->window.draw(IPMG);
  	engine->window.draw(IPFT);
  	engine->window.draw(IPRL);

    engine->window.draw(TowerMachine);
    engine->window.draw(TowerFlame);
    engine->window.draw(TowerRocket);

    engine->window.draw(MachinegunTowerPrice);
    engine->window.draw(FlamethrowerTowerPrice);
    engine->window.draw(RocketlauncherTowerPrice);

    if (InvalidPlacement && !InvalidPlacementMenu) {
        engine->window.draw(CrossMarker);
        InvalidPlacementMenu = false;
    }

    if (engine->isTimeOut() && !GameIsPaused) {
        TimeToNextWave.setString("Next wave in: " + std::to_string(engine->TimeToNextRound()));
    } else {
        TimeToNextWave.setString("INCOMING!");
    }

    engine->window.draw(TimeToNextWave);

    if (engine->getHP() <= 0) {
        GameOverText.setString("GAME OVER!\nWAVES SURVIVED: " + std::to_string(engine->getLevel()) + "\nTOTAL SCORE: " + std::to_string(engine->getScore()) + "\nPLAYER NAME: ");
        engine->window.draw(InputToName);
        engine->window.draw(GameOverText);
    }

  	for(auto& text : topScores){
  		engine->window.draw(TopScoreHL);
  		engine->window.draw(text);
	  }

    if (GameIsPaused) {
        engine->window.draw(ScreenWhenPaused);
        engine->window.draw(PausedGameTitle);
        engine->window.draw(ContinueButton);
        engine->window.draw(ExitGameButton);
        //engine->window.draw(SaveGameButton);
    }

    engine->window.draw(MouseCursor);
    engine->window.display();
    
}
