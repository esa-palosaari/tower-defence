#include "GameMenu.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>


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
    SetToText(MenuGameButton, 660.f, 380.f, Font, 128);

    StartGameButton.setFont(Font); // -> exitStatus = 1
    StartGameButton.setString("START GAME");
    SetToText(StartGameButton,690.f, 530.f, Font, 64);
    
    LoadGameButton.setFont(Font); // -> exitStatus = 2
    LoadGameButton.setString("LOAD GAME");
    SetToText(LoadGameButton, 690.f, 595.f, Font, 64);
    
    ExitGameButton.setFont(Font); // -> exitStatus = 0
    ExitGameButton.setString("EXIT GAME");
    SetToText(ExitGameButton, 690.f, 660.f, Font, 64);
	
	TopScoreHL.setFont(Font);
	TopScoreHL.setString("TOP 10 PLAYERS:");
	SetToText(TopScoreHL,30.f,410.f,Font,64);

    MenuOn = true;
}

// Gets the 10 best players and stores them in a new vector? 
void GameMenu::showHighScores(){
	if(!topScoresInit){
			topScoresInit = true;
			float y = 500.f;
			int i = 1;
			for(auto& score : topScoresVec){
				sf::Text temp;
				temp.setFont(Font);
				temp.setCharacterSize(30);
				temp.setPosition(50.f, y);
				temp.setString(std::to_string(i) + ". " + score.name + "- Score: " + std::to_string(score.score));
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

void GameMenu::SetToText(sf::Text& textinput, float PositionX, float PositionY, sf::Font Font, int Size){
    textinput.setPosition(PositionX, PositionY);
    textinput.setCharacterSize(Size);
}

void GameMenu::StartScores(){
	if(MenuOn){
	showTopScoreClk.restart();
	std::string line;
	std::ifstream myfile("../src/maps/scores.txt");
	if(myfile.is_open()){
		int i = 1;
		Sores temp;
		while(getline(myfile, line, ';')){
			//std::cout<<line<<'\n';
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
			switch(i){
				case 1:
					temp.name = line;
					break;
				case 2:
					temp.score = stoi(line);
					break;
			}
			i++;
			if(i > 2){
				i = 1;
				topScoresVec.push_back(temp);
				Sores temp;
			}
		}
		myfile.close();
		std::sort(topScoresVec.begin(), topScoresVec.end());
	}
	else{
		std::cout<<"Unable to open file";
	}
    }
}

bool GameMenu::showTopScore(){
	if(MenuOn && showTopScoreClk.getElapsedTime().asSeconds() > 1){
		return true;
	}
	return false;
}

int GameMenu::StartMenu(){
	int exit_ret; // exit status 
	sf::Music music; // music object
	music.setLoop(true); 
	// loading music
	if (!music.openFromFile("../src/sounds/radio.ogg")){
		std::cout << "Opening radio.ogg failed!" << std::endl;
    	return -1; // error
	}
	music.play(); // play music


	while(nWindow.isOpen()){
        	exit_ret = manageEvents(); // start manage events
		StartScores();
		showHighScores();
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
					MenuOn=false;
					nWindow.close();
                }
                
                else if (LoadGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                   	exitStatus = 2; // -> load game
					MenuOn=false;
					nWindow.close();
                }
                
                else if (ExitGameButton.getGlobalBounds().contains(mouse.x, mouse.y))
                {
                	exitStatus = 0; // -> exit game
					MenuOn=false;
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
	for(auto& text : topScores){
		nWindow.draw(TopScoreHL);
		nWindow.draw(text);
	}
	nWindow.display();
}

