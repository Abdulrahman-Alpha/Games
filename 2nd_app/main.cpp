#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf ;
using namespace std;
int main (int argc, char ** argv){
  RenderWindow renderWindow(VideoMode(850, 600), "Demo Game");

  Event event;

  Texture texture;
    if (!texture.loadFromFile("image.jpg"))
    {
     //error...
    cout << " load failed " << endl;
    system ("pause");
    }
    Sprite sprite;
    sprite.setTexture(texture);
    Font font ;
  if (!font.loadFromFile("FontFile.ttf"))
  {
      cout << " Error loading file " << endl;
      system("pause");
  }
  Text text ;
  text.setFont(font);
  text.setString(" Welcome To Panic Room ");
  text.setCharacterSize( 150 );
  text.setColor(Color::Red);
  //sprite.setTextureRect(IntRect(90,90,40,40));
  //sprite.setColor(Color::Red);
  while(renderWindow.isOpen()){
      while (renderWindow.pollEvent(event)){
        if (event.type == Event::EventType::Closed)
          renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw( sprite );
    renderWindow.draw( text );
    renderWindow.display();
}
}
