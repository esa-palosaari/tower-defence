#include "UserGraphics.hpp"
#include <iostream>

UserGraphics::UserGraphics(Engine* engine) : Game(engine){
    //Textuurit ja fontit + muut alustetaan tässä!
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
                    Game->Update(FPSTime);         //Update is requested.
                }
                else if(GamePaused){               //If game is paused, additional measurements are requested.
                    managePause();
                }
                else{                              //If there is no HP left, ending must be managed as well.
                    Game->Update(FPSTime);
                    manageEnd();
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
