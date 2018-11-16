#include "UserGraphics.hpp"
#include <iostream>

UserGraphics::UserGraphics(Engine* engine) : Game(engine){
    //Textuurit ja fontit + muut alustetaan tässä!

  sf::Texture textureTowerBase0;
  if(textureTowerBase0.loadFromFile("../src/photos/towerBase0.png")) {
    std::cout << "Error loading image towerBase0.png" << std::endl;
  }
  sf::Sprite spriteTowerBase0(textureTowerBase0);

  sf::Texture textureTowerBase1;
  if(textureTowerBase1.loadFromFile("../src/photos/towerBase1.png")) {
    std::cout << "Error loading image towerBase1.png" << std::endl;
  }
  sf::Sprite spriteTowerBase1(textureTowerBase1);

  sf::Texture textureTowerBase2;
  if(textureTowerBase2.loadFromFile("../src/photos/towerBase2.png")) {
    std::cout << "Error loading image towerBase2.png" << std::endl;
  }
  sf::Sprite spriteTowerBase2(textureTowerBase2);
}

void UserGraphics::StartUserGraphics(){
    while(Game->window.isOpen()){
        sf::Clock clock;
        sf::Time timeSLU = sf::Time::Zero;          //Update aina kun tämä ylittyy FPSTime.
        while(Game->window.isOpen()){               //Continues to do something while window is open.
            if(Game->getHP() > 0 && !GamePaused){
                manageEvents();                     //Manages and processes user input
            }
            timeSLU += clock.restart();             //Add the time cumulated since last update to reserves.
            while(timeSLU > FPSTime){               //When time reserves are higher than time per single frame, triggers the engine to update game's state.
                timeSLU -= FPSTime;                 //Time per frame is substituted and overtime remains in time reserves.
                if(Game->getHP() > 0 && !GamePaused){
                    manageEvents();
                    Game->Update(FPSTime);         //Update is requested to update the current frame to next frame.
                }
                else if(GamePaused){               //If game is paused, additional measurements are requested.
                    managePause();                  //Manages possible user input while game is paused.
                }
                else{                              //If there is no HP left, ending must be managed as well.
                    Game->Update(FPSTime);      //Engine's Update-function is called.
                    manageEnd();                //End-times user input is managed.
                }
            }
            render();                             //Window and graphics must be rendered at the end of each loop.
        }
    }
}

void manageEvents(){
    
}

void manageEnd(){
    
}

void managePause{
    
}

void render{
    
}
