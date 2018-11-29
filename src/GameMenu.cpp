#include "GameMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

GameMenu::GameMenu() : nWindow(sf::VideoMode(1920, 1080), "GameMenu", sf::Style::None), title(), titleTexture()
{
    if (!Font.loadFromFile("../src/photos/FontFile.ttf")) {
        std::cout << "Can't load font" << std::endl;
	}
	
    if(!titleTexture.loadFromFile("../src/photos/menu.png")){
        std::cout << "Opening menu.png failed!" << std::endl;
    }
    else{
        title.setTexture(titleTexture);
    }
	    
	MenuGameButton.setFont(Font); // -> just a title
    MenuGameButton.setString("GAME MENU");
    SetToText(MenuGameButton, 800.f, 420.f, Font, 64);

    StartGameButton.setFont(Font); // -> exitStatus = 1
    StartGameButton.setString("START GAME");
    SetToText(StartGameButton, 800.f, 530.f, Font, 32);
    
    LoadGameButton.setFont(Font); // -> exitStatus = 2
    LoadGameButton.setString("LOAD GAME");
    SetToText(LoadGameButton, 800.f, 595.f, Font, 32);
    
    ExitGameButton.setFont(Font); // -> exitStatus = 0
    ExitGameButton.setString("EXIT GAME");
    SetToText(ExitGameButton, 800.f, 660.f, Font, 32);

    	
}

void GameMenu::SetToText(sf::Text& textinput, float PositionX, float PositionY, sf::Font Font, int Size){
    textinput.setPosition(PositionX, PositionY);
    textinput.setCharacterSize(Size);
}

int GameMenu::StartMenu(){
	int exit_ret;    
	while(nWindow.isOpen()){
        exit_ret = manageEvents();
        render();
    }
	return exit_ret;
}

int GameMenu::manageEvents(){


    sf::Event event;
    while(nWindow.pollEvent(event))
    {
        sf::Vector2i mouse(sf::Mouse::getPosition(nWindow).x, sf::Mouse::getPosition(nWindow).y);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (StartGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
          			exitStatus = 1;
					nWindow.close();
                }
                
                else if (LoadGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                   	exitStatus = 2;
					nWindow.close();
                }
                
                else if (ExitGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                	exitStatus = 0;
					nWindow.close();
                }
            }
        }
     }
	return exitStatus;
}



void GameMenu::render(){
    nWindow.clear(sf::Color::Black);
	nWindow.draw(title);
	nWindow.draw(MenuGameButton);
	nWindow.draw(StartGameButton);
	nWindow.draw(LoadGameButton);
	nWindow.draw(ExitGameButton);
	nWindow.display();
}

