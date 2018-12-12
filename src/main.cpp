#include "GameTitle.hpp"
#include "GameMenu.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main(){

	int exitStatus;
	std::cout << "Game is starting.." << std::endl;

	GameTitle title;
	title.StartTitle();

	GameMenu menu;
	exitStatus = menu.StartMenu();

	if (exitStatus == 1) {
 		Engine engine;
		engine.StartEngine();
	} else {
		std::cout << "Game is closing..." << std::endl;
	}

	std::cout << "Game is closed." << std::endl;

}
