#ifndef UserGraphics_hpp
#define UserGraphics_hpp

class UserGraphics{
public:
  UserGraphics(Engine* engine);
    void Start();
    void render();
    void processEvents();
    void processEndInput();
    void processPause();
private:
    Engine* Game;
    const sf::Time FPSTime = sf::seconds(1.f / 60.f); //Time until an update is called to update the current frame to next one.
    bool GamePaused = false;
  sf::Texture textureTowerBase0;
  sf::Texture textureTowerBase1;
  sf::Texture textureTowerBase2;
  sf::Sprite spriteTowerBase0;
  sf::Sprite spriteTowerBase2;
  sf::Sprite spriteTowerBase1;
  sf::Texture textureEnemy1;
  sf::Texture textureEnemy2;
  sf::Texture textureEnemy3;
  sf::Sprite spriteEnemy1;
  sf::Sprite spriteEnemy2;
  sf::Sprite spriteEnemy3;  
};

#endif 
