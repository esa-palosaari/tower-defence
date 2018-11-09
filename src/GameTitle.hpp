#ifndef GameTitle_hpp
#define GameTitle_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameTitle{
public:
    GameTitle();
    void StartTitle();
    void manageEvents();
    void render();
private:
	sf::RenderWindow nWindow;
	sf::Sprite title;
	sf::Texture titleTexture;
};
#endif
