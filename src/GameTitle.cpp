#include "GameTitle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

GameTitle::GameTitle() : nWindow(sf::VideoMode(1920, 1080), "GameTitle", sf::Style::None), title(), titleTexture() {
    if(!titleTexture.loadFromFile("../src/photos/kuva.png")){
        std::cout << "Opening title.png failed!" << std::endl;
    } else {
        title.setTexture(titleTexture);
    }
}

// Starts the Gametitle view
void GameTitle::StartTitle() {
    while(nWindow.isOpen()){
        manageEvents();
        render();
    }
}

// Manages users input
void GameTitle::manageEvents(){
    sf::Event event;
    while(nWindow.pollEvent(event)){
        if(event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed){
            nWindow.close();
        }
    }
}

// Renders the window
void GameTitle::render(){
    nWindow.clear();
    nWindow.draw(title);
    nWindow.display();
}

// Destructor
GameTitle::~GameTitle() {

}
