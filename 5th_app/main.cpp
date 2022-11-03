#include <time.h>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;
struct point
{ int x,y;};

int main(int argc, char ** argv)
{
    srand(time(0));

    RenderWindow app(VideoMode(533, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("images/background.jpg");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");

    SoundBuffer buf;
	if(!buf.loadFromFile("Audio.wav"));

	Sound sound;
	sound.setBuffer(buf);
	sound.setVolume(10);
    sound.play();
    Text text, score;
    Font font;


    if(not font.loadFromFile("FontFile.ttf")){
        cout << "can not load the fonts" << "\n";
        system("pause");
    }

    score.setFont(font);
    score.setCharacterSize(50);
    score.setPosition(400, 50);
    score.setColor(Color::White);
    text.setFont(font);
    text.setString("Game Over ..");
    text.setCharacterSize(200);
    text.setColor(Color::Red);
    int Tscore = 0 ;
    Sprite sBackground(t1), sPlat(t2),sPers(t3);
    point plat[20];
    Clock clock;
    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

    int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {

        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=4;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=4;

    dy+=0.2;
    y+=dy;
    if (y>500){
       sound.stop();
       dy=10;
       system("pause");
       cout<< "Game Over" << endl;
       app.close();
    }


/*     bool check()
{
   for (int i=0;i<4;i++)
      if (a[i].x<0 || a[i].x>=N || a[i].y>=M) return 0;
      else if (field[a[i].y][a[i].x]) re       turn 0;

   return 1;
};
*/      if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }

    for (int i=0;i<10;i++)
     if ((x+50>plat[i].x) && (x+20<plat[i].x+68)&& (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))
     {
       Tscore += 5 ;
       dy=-10;
     }
    sPers.setPosition(x,y);
     if(sPers.getPosition().x + sPers.getGlobalBounds().width>533){
        sPers.setPosition(533-sPers.getGlobalBounds().width,sPers.getPosition().y);
        dx = -5;
     }
     if(sPers.getPosition().x <0.f){
        sPers.setPosition(0.f,sPers.getPosition().y);
        dy = -5;
     }
    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }
    score.setString(to_string(Tscore));
    app.draw(score);
    app.display();
}

}
