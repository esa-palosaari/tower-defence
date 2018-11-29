#ifndef GameMenu_hpp
#define GameMenu_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class GameMenu{
public:
    GameMenu();
	~GameMenu();
    int StartMenu();
    int manageEvents();
    void render();
	void SetToText(sf::Text& text, float x, float y, sf::Font font, int size);
private:
	sf::RenderWindow nWindow;
	sf::Font Font;
	sf::Text MenuGameButton;
  	sf::Text StartGameButton;
	sf::Text LoadGameButton;
	sf::Text ExitGameButton;
	int exitStatus;
	sf::Sprite title;
	sf::Texture titleTexture;
};
#endif
