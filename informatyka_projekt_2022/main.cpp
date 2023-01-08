#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Statek {
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
public:
	Statek(float x_in, float y_in, float sizex_in, float sizey_in);
	void przesun(float x_in, float y_in);
	sf::Sprite getStatek() { return pSprite; }
	sf::Vector2f getPosition(){ return position; }
};
Statek::Statek(float x_in, float y_in, float sizex_in, float sizey_in)
{
	position.x = x_in;
	position.y = y_in;
	tekstura.loadFromFile("statek.png");
	pSprite.setTexture(tekstura);
	pSprite.setPosition(position);
	rozmiar_okna.x = sizex_in;
	rozmiar_okna.y = sizey_in;
}
void Statek::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;

	if (position.x <= 1150 && position.x >= 50) {
		pSprite.move(pos);
	}
	else if (position.x > 1150)
	{
		pSprite.move(-1150.0, 0);
		

	}
	else if (position.x < 0)
	{
		pSprite.move(1150.0, 0.0);
	}
	else
	{
		pSprite.move(pos);
	}
	
	position = pSprite.getPosition();
}

class pocisk
{
private:
	sf::Vector2f position2;
	float yVel2 = -5;
	sf::Texture tekstura2;
	sf::Sprite pSprite2;
	
public:
	pocisk(float x_in, float y_in);
	sf::Sprite getPocisk() { return pSprite2; }
	void animuj();
	void przesun2(float y_in);
	void setPosition(float x_in, float y_in);
};
pocisk::pocisk(float x_in, float y_in) {
	position2.y = y_in;
	position2.x = x_in;
	tekstura2.loadFromFile("pocisk.png");
	pSprite2.setTexture(tekstura2);
	pSprite2.setPosition(position2);
}
void pocisk::animuj()
{
	przesun2(yVel2);
}
void pocisk::przesun2(float y_in)
{
	sf::Vector2f pos;
	pos.y = y_in;
	pSprite2.move(pos);
}
void pocisk::setPosition(float x_in, float y_in)
{
	position2.x = x_in;
	position2.y = y_in;
	pSprite2.setPosition(position2);
}
class invader {
private:
	sf::Vector2f position3;
	float xVel3 = 1, yVel3 = 0;
	sf::Texture tekstura3;
	sf::Sprite pSprite3;
public:
	invader(float x_in, float y_in, float xVel_in, float yVel_in);
	void przesun3(float x_in, float y_in);
	sf::Sprite getInvader() { return pSprite3; }
	sf::Vector2f getPosition() { return position3; }
	void animuj3();
};
invader::invader(float x_in, float y_in, float xVel_in, float yVel_in)
{
	position3.x = x_in;
	position3.y = y_in;
	xVel3 = xVel_in;
	yVel3 = yVel_in;
	tekstura3.loadFromFile("invader.png");
	pSprite3.setPosition(position3);
	pSprite3.setTexture(tekstura3);
}
void invader::przesun3(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	

	if (position3.x <= 1150 && position3.x >= 50) {
		pSprite3.move(pos.x,pos.y);

	}
	else if (position3.x > 1150)
	{
		pSprite3.move(-1150.0, 0);


	}
	else if (position3.x < 0)
	{
		pSprite3.move(1150.0, 0.0);
	}
	else
	{
		pSprite3.move(pos);
	}

	position3 = pSprite3.getPosition();
}
void invader::animuj3() {
	przesun3(xVel3, yVel3);
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Projekt infa");
	sf::Event event;
	Statek pb(580, 730, window.getSize().x - 100, window.getSize().y - 100);
	pocisk bl(2000, 100);
	invader i1(5, 100,1,0);
	
	sf::Clock zegar;
	sf::Clock zegar2;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::A)
					{
						pb.przesun(-10, 0);
					}
					if (event.key.code == sf::Keyboard::D)
					{
						pb.przesun(10, 0);
					}
					
				}
				if (event.key.code == sf::Event::KeyPressed);
				{
					if (event.key.code == sf::Keyboard::Space)
					{
						if (zegar2.getElapsedTime().asSeconds() > 1.0f)
						{
							bl.setPosition(pb.getPosition().x + 20, pb.getPosition().y + 35);
							zegar2.restart();
						}
					}
				}
			}
		}
		window.clear(sf::Color::Black);
		window.draw(pb.getStatek());
		window.draw(bl.getPocisk());
		window.draw(i1.getInvader());
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
		{
			bl.animuj();
			i1.animuj3();
			zegar.restart();

		}
		window.display();
	}
	return 0;
}