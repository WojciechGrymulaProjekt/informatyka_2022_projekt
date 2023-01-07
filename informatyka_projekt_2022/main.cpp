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
	void animuj();
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

	if (position.x != 1150 && position.x != 50) {
		pSprite.move(pos);
	}
	else if (position.x >= 1150)
	{
		pSprite.move(-1099.0, 0);

	}
	else if (position.x <= 50)
	{
		pSprite.move(1099.0, 0.0);
	}
	else
	{
		pSprite.move(pos);
	}
	position = pSprite.getPosition();
}
void Statek::animuj()
{
	przesun(xVel, yVel);
}
class pocisk
{
private:
	sf::Vector2f position2;
	float xVel = 1, yVel = 1;
	sf::Texture tekstura2;
	sf::Sprite pSprite2;
public:

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Projekt infa");
	sf::Event event;
	sf::Texture tekstura;
	sf::Sprite pokeball(tekstura);
	Statek pb(580, 730, window.getSize().x - 100, window.getSize().y - 100);
	sf::Clock zegar;
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
					if (event.key.code == sf::Keyboard::W)
					{

						pb.przesun(0, -10);
					}
					if (event.key.code == sf::Keyboard::S)
					{
						pb.przesun(0, 10);
					}
					if (event.key.code == sf::Keyboard::A)
					{
						pb.przesun(-10, 0);
					}
					if (event.key.code == sf::Keyboard::D)
					{
						pb.przesun(10, 0);
					}
				}
			}
		}
		window.clear(sf::Color::Black);
		window.draw(pb.getStatek());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
		{
			//pb.animuj();

			zegar.restart();
		}

	}
	return 0;
}