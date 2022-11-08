#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf ;
using namespace std;
/*int main(int argc, char ** argv)
{
    RenderWindow renderWindow(VideoMode(640,480),"SFML Demo");
    Event event;
    while(renderWindow.isOpen()){
      while (renderWindow.pollEvent(event)){
        if (event.type == Event::EventType::Closed)
          renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.display();
  }
}*/

/*int main(int argc, char ** argv) {
   RenderWindow renderWindow(VideoMode(640, 480), "SFML Demo");

   Event event;

  // A Clock starts counting as soon as it's created
   Clock clock;

   while(renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      //Handle events here
      if (event.type == Event::EventType::Closed)
        renderWindow.close();
      if((event.type == Event::KeyPressed) && ((event.key.code == Keyboard::Escape)||(event.key.code == Keyboard::Space)))
          renderWindow.close();
    }

    // A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
    cout<< "Elapsed time since previous frame(microseconds): " << clock.getElapsedTime().asMicroseconds() << endl;
    clock.restart();
    renderWindow.clear();
    renderWindow.display();
}
  }
*/
// This example demostrates the main loop


/*int main(int argc, char ** argv) {
  RenderWindow renderWindow(VideoMode(640, 480), "SFML Demo");

  Event event;

  // A Clock starts counting as soon as it's created
  Color color(Color::White);
  Color rcolor(Color::Red);
  Color gcolor(Color::Green);
  // C++ 11 way of generating a random between 0 - 255
  // mt19937 is an implementation of the Mersenne Twister pseudo random number generator
  // random_device() returns a random number to use as a seed for the mt algorithm... slow however so that's why we dont just use it for all randoms if you were wondering
  // mt results arent in a human friendly format, so we use uniform_int_distribution to "shape" the results to our range and type
  // uniform_int_distribution is a fairly "light" object.  random_device and mt19937 aren't.
  uniform_int_distribution<int> randomColorRange(0, 255);
  random_device rd;
  mt19937 randomNumbers(rd());

  // Pre-C++ 11 but more common way (*with issues, see:
  //https://www.reddit.com/r/programming/comments/1rnudl/quite_interesting_why_cs_rand_is_considered/
  // Mostly doesn't apply to game devs if not using rand for say... security.

  /*
  srand(time(NULL));          //seed random number generator with the current time
  auto randomNumber = rand() % 255;   //generate a random number then confine it to a value of 0 - 255.
  */

  /*while (renderWindow.isOpen()){
    // Check for all the events that occured since the last frame.
    while (renderWindow.pollEvent(event)){
      //Handle events here
      if (event.type == Event::EventType::Closed)
        renderWindow.close();

      //Respond to key pressed events
      if (event.type == Event::EventType::KeyPressed){
        if (event.key.code == Keyboard::Space){
          color.r = randomColorRange(randomNumbers);
        }
      }
    }


    // Now demonstrate input via polling
    if (Keyboard::isKeyPressed(Keyboard::R))
      if (Keyboard::isKeyPressed(sf::Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl))
        color.r = 0;
      else
        color.r = randomColorRange(randomNumbers);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        color.g = 0;
      else
        color.g = randomColorRange(randomNumbers);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        color.b = 0;
      else
        color.b = randomColorRange(randomNumbers);



    renderWindow.clear(color);
    renderWindow.display();
  }

}*/
// This example demostrates the main loop

// Demonstrate primitve drawing in SFML
/*int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;

  CircleShape circleShape(200);
  circleShape.setOrigin(circleShape.getRadius(), circleShape.getRadius());

  circleShape.setFillColor(Color::Blue);
  circleShape.setPosition(100.0f, 100.0f);
  CircleShape circleShape2(200);
  circleShape2.setPosition(0.0f,0.0f);
  circleShape2.setFillColor(Color::Red);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(circleShape);
    renderWindow.display();
  }
  // or you could have calculated the mid point like so:
  // circleShape.setOrigin(circleShape.getLocalBounds().width / 2.0f, circleShape.getLocalBounds().height / 2.0f);

    //snip

    renderWindow.clear();
    renderWindow.draw(circleShape);
    renderWindow.draw(circleShape2);
    renderWindow.display();

}*/
#include "SFML/Graphics.hpp"

/*int main(int argc, char ** argv){
  RenderWindow renderWindow(VideoMode(700, 500), "Demo Game");

  Event event;

  CircleShape circleShape(200);
  circleShape.setFillColor(Color::Green);
  circleShape.setPosition(50.0f, 50.0f);
  circleShape.setOutlineThickness(10);
  circleShape.setOutlineColor(Color::White);
  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(circleShape);
    renderWindow.display();
  }


}
*/
/*int main(int argc, char ** argv){
  RenderWindow renderWindow(VideoMode(700, 500), "Demo Game");

  Event event;

  ConvexShape convexShape;
  convexShape.setPointCount(5);
  convexShape.setFillColor(sf::Color(147, 112, 227)); // PURPLE!
  convexShape.setOutlineThickness(5.0f);
  convexShape.setOutlineColor(sf::Color::White);
  convexShape.setPoint(0, sf::Vector2f(0.0f, 0.0f));
  convexShape.setPoint(1, sf::Vector2f(renderWindow.getSize().x, 0.0f));
  convexShape.setPoint(2, sf::Vector2f(renderWindow.getSize().x, renderWindow.getSize().y));
  convexShape.setPoint(3, sf::Vector2f(renderWindow.getSize().x / 2, renderWindow.getSize().y / 2));
  convexShape.setPoint(4, sf::Vector2f(0, renderWindow.getSize().y));
  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(convexShape);
    renderWindow.display();
  }


}
*/
/*int main (int argc, char ** argv){
  RenderWindow renderWindow(VideoMode(600, 600), "Demo Game");

  Event event;
  RectangleShape line(sf::Vector2f(200, 5));
  line.rotate(45);
  while(renderWindow.isOpen()){
      while (renderWindow.pollEvent(event)){
        if (event.type == Event::EventType::Closed)
          renderWindow.close();
    }
    renderWindow.clear();
    renderWindow.draw(line);
    renderWindow.display();
}
}
*/
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
/*#include <SFML/Graphics.hpp>
#include <iostream>
#define pi 3.14
using namespace sf;
using namespace std;

void update(int &moved , CircleShape &circle);
void draw(RenderWindow &target , CircleShape &circle);

int main()
{
    RenderWindow renderWindow(VideoMode(1080 , 720), "Game Hub");
    renderWindow.setFramerateLimit(60);
    Event event;


    CircleShape triangle(200.f);
    triangle.setPointCount(3);
    triangle.setPosition(Vector2f(50.f , 50.f));
    triangle.setFillColor(Color::Blue);



    int moved = 8;




    while(renderWindow.isOpen())
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == Event::EventType::Closed || event.key.code == Keyboard::Escape)
                renderWindow.close();

        }


        update(moved ,triangle);
        draw(renderWindow , triangle);
    }

    return 0;
}

void update(int &moved , CircleShape &circle)
{

    if(moved < 8)moved++;

    if(Keyboard::isKeyPressed(Keyboard::A) )
    {
        circle.move(-5.0f , 0);
        moved = 0;
    }

    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        circle.move(0 , 5.0f);
        moved = 0;
    }

    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        circle.move(0 , -5.0f);
        moved = 0;
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        circle.move(5.0f , 0);
        moved = 0;
    }


    if(Mouse::isButtonPressed(Mouse::Right))
        circle.setFillColor(Color::Yellow);
    else circle.setFillColor(Color::Red);



}

void draw(RenderWindow &target , CircleShape &circle)
{
    target.clear(Color::White);
    target.draw(circle);
    target.display();
}
*/
