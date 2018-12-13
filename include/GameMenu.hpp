#ifndef GameMenu_hpp
#define GameMenu_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>

class TopScores {	// Class for top scores in game

public:
	std::string name;
	int score;
	bool operator <(const TopScores& d){
		if(score > d.score){
			return true;
		}
		return false;
	}
};

class GameMenu{
public:
		GameMenu();
    int StartMenu();
		bool showTopScore();	// is it needed?
    int manageEvents();
		void StartScores();
		void showHighScores();
    void render();
		void SetToText(sf::Text& text, float x, float y, sf::Font font, int size);
		std::vector<TopScores> topScoresVec; // Existing top scores
		std::vector<sf::Text> topScores; // Renewed vector
private:
		sf::RenderWindow nWindow;
		sf::Font Font;
		sf::Text MenuGameButton;
	  sf::Text StartGameButton;
		sf::Text LoadGameButton;
		sf::Text ExitGameButton;
		sf::Text TopScoreHL;
		int exitStatus;
		sf::Sprite title;
		sf::Texture titleTexture;
		sf::Music music;
		bool MenuOn = true;
		bool topScoresInit = false;
		sf::Clock showTopScoreClk;
		sf::SoundBuffer Click;
		sf::Sound ClickSound;
};
#endif
