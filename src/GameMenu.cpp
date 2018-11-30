#include "GameMenu.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

GameMenu::GameMenu() : nWindow(sf::VideoMode(1920, 1080), "GameMenu", sf::Style::None), title(), titleTexture(), music()
{
	// loading font
    if (!Font.loadFromFile("../src/photos/army.ttf")) {
        std::cout << "Can't load font" << std::endl;
	}
	
	// loading background picture
    if(!titleTexture.loadFromFile("../src/photos/menu.png")){
        std::cout << "Opening menu.png failed!" << std::endl;
    }
    else{
        title.setTexture(titleTexture);
    }

	
	// Creating menu text items    
	MenuGameButton.setFont(Font); // -> just a title
    MenuGameButton.setString("GAME MENU");
    SetToText(MenuGameButton, 790.f, 380.f, Font, 128);

    StartGameButton.setFont(Font); // -> exitStatus = 1
    StartGameButton.setString("START GAME");
    SetToText(StartGameButton,810.f, 530.f, Font, 64);
    
    LoadGameButton.setFont(Font); // -> exitStatus = 2
    LoadGameButton.setString("LOAD GAME");
    SetToText(LoadGameButton, 810.f, 595.f, Font, 64);
    
    ExitGameButton.setFont(Font); // -> exitStatus = 0
    ExitGameButton.setString("EXIT GAME");
    SetToText(ExitGameButton, 810.f, 660.f, Font, 64);

    	
}

void GameMenu::SetToText(sf::Text& textinput, float PositionX, float PositionY, sf::Font Font, int Size){
    textinput.setPosition(PositionX, PositionY);
    textinput.setCharacterSize(Size);
}

int GameMenu::StartMenu(){
	int exit_ret; // exit status 
	sf::Music music; // music object
	music.setLoop(true); 
	// loading musid
	if (!music.openFromFile("../src/sounds/radio.ogg")){
		std::cout << "Opening wagner.ogg failed!" << std::endl;
    	return -1; // error
	}
	music.play(); // play music   
	while(nWindow.isOpen()){
        exit_ret = manageEvents(); // start manage events
		render(); // start rendering
    }
	return exit_ret;
}

int GameMenu::manageEvents(){

    sf::Event event; // event object
    while(nWindow.pollEvent(event))
    {
        sf::Vector2i mouse(sf::Mouse::getPosition(nWindow).x, sf::Mouse::getPosition(nWindow).y);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (StartGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
          			exitStatus = 1; // -> start a new game
					nWindow.close();
                }
                
                else if (LoadGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                   	exitStatus = 2; // -> load game
					nWindow.close();
                }
                
                else if (ExitGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                	exitStatus = 0; // -> exit game
					nWindow.close();
                }
            }
        }
     }
	return exitStatus;
}


void GameMenu::render(){
	// draw everything    
	nWindow.clear(sf::Color::Black);
	nWindow.draw(title);
	nWindow.draw(MenuGameButton);
	nWindow.draw(StartGameButton);
	nWindow.draw(LoadGameButton);
	nWindow.draw(ExitGameButton);
	nWindow.display();
}

