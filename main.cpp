#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
  
  sf::Texture playerTexture;
  sf::Sprite playerSprite;

  if (playerTexture.loadFromFile("Assets/Player/Textures/playersprite.png"))
  {
    std::cout << "Texture load successful" << std::endl;
    playerSprite.setTexture(playerTexture);

    int XIndex = 0;
    int YIndex = 0;

    playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    playerSprite.scale(sf::Vector2f(0.5, 0.5));
  }
  else 
  {
    std::cout << "Textures failed to load" << std::endl;
  }

  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(20, 20));
  rectangle.setFillColor(sf::Color::Magenta);
  rectangle.setPosition(sf::Vector2f(6.8, 8.8));
  
  // Main game loop
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
     
    }
    
   
    sf::Vector2f position = playerSprite.getPosition();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      playerSprite.setPosition(position + sf::Vector2f(0.08, 0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      playerSprite.setPosition(position + sf::Vector2f(-0.08, 0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      playerSprite.setPosition(position + sf::Vector2f(0, -0.08));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      playerSprite.setPosition(position + sf::Vector2f(0, 0.08));
    }

    window.clear(sf::Color::Black);
    window.draw(rectangle);
    window.draw(playerSprite);

    window.display();
  }

  return 0;
}