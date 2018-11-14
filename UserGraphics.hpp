#ifndef UserGraphics_hpp
#define UserGraphics_hpp

class UserGraphics{
public:
    GraphTD(GameState* game);
    void Start();
    void render();
    void processEvents();
    void processEndInput();
    void processPause();
private:
    Engine* Game;
    const sf::Time FPSTime = sf::seconds(1.f / 60.f); //Frames per second.
    bool GamePaused = false;
}

#endif 