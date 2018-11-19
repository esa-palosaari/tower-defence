#include "GameTitle.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

int main(){
	std::cout << "Game is starting.." << std::endl;
	GameTitle title;
	title.StartTitle();

	Engine engine;
	engine.StartEngine();

	std::cout << "Game is closed." << std::endl;
}
