#ifndef UserGraphics_hpp
#define UserGraphics_hpp

class UserGraphics{
public:
    GraphTD(GameState* game);
    void Start();
    void setText(sf::Text& text, float x, float y, sf::Font font, int size);
    template <class t>
    bool insideBounds(t sprite, sf::Vector2f pos);
    template <class t>
    bool insideBounds(t sprite, sf::Vector2i pos);
    bool inRoad(sf::Vector2f pos);
    void createTower(Types::NPC type, int losePoints);
    void drawMovableTower(float posx, float posy, sf::Vector2f pos);
    bool notInroad(sf::Vector2f pos);
    void render();
    void processEvents();
    void processEndInput();
    void processPause();
    template <class t, class y>
    bool insideBounds(t sprite, y pos);
private:
    Engine* Game;
    const sf::Time FPSTime = sf::seconds(1.f / 60.f); //Frames per second.
    bool GamePaused = false;
}

#endif /* UserGraphics_hpp */
