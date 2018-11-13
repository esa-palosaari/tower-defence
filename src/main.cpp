#include "GameTitle.hpp"
#include "TileMap.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

// create a tilemap from a textfile
// https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php

int main(){
    std::cout<<"Game is starting.."<<std::endl;
    //GameTitle title;
    //    title.StartTitle();

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // fake test file input
    /*    std::istringstream is("0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,"); */

    //    const int level[] =
    //{
    //};

    // Read text file
    std::vector<int> level;
    std::string number_as_string;
    std::string fname = "../src/maps/Map1.txt";
    std::ifstream istr(fname.c_str());
    if(istr.rdstate() & (istr.failbit | istr.badbit)) {
      std::cerr << "Failed to read file" << std::endl;
    } else {
      while (std::getline(istr, number_as_string, ',')) {
      level.push_back(atoi(number_as_string.c_str()));
    }
    }
    
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("../src/photos/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), &level[0], 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }



    
    std::cout<<"Game is closed."<<std::endl;
}

// /Users/oskartainio/Documents/Ohjelmointi/C++ -ohjelmointi/Projekti/GameTitle/GameTitle/ExternalLibraries/SFML/include/SFML
