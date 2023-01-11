#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
class Player {
private:
	int score=0;
public:
	Player(int score_in);
	int getScore() { return score; }
	void drawScore();
	void setScore(int score_in);
};
Player::Player(int score_in) {
	score = score_in;
}
void Player::drawScore() {
	printf("%d", score);
}
void Player::setScore(int score_in) {
	score = score_in;
}
class Statek {
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
	int zycie = 3;
public:
	Statek(float x_in, float y_in, float sizex_in, float sizey_in);
	void przesun(float x_in, float y_in);
	sf::Sprite getStatek() { return pSprite; }
	sf::Vector2f getPosition() { return position; }
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
	sf::Vector2f getPosition() { return position2; }
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
	void sprawdzKolizjeSciany();
	void smierc();

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
		pSprite3.move(pos.x, pos.y);

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
void invader::sprawdzKolizjeSciany()
{
	if (position3.x <= 10)
	{
		xVel3 = 1;
		pSprite3.move(0, 10);
	}
	if (position3.x >= 1150)
	{
		pSprite3.move(0, 10);
		xVel3 = -1;
	}

	if (position3.y >= 730)
		yVel3 = -1;
}
void invader::smierc()
{
	xVel3 = 0;
	yVel3 = 0;
	pSprite3.move(1000, 100000);
}
class invader2 {
private:
	sf::Texture invader;
	sf::Sprite* invaderT;
	int N;
	float xVel = 1, yVel = 0;
	int kill = 0;
public:

	invader2(int N);
	void draw(sf::RenderWindow& window);
	void move2(float xVel_in, float yVel_in);
	void sprawdzKolizje();
	void getInvaders(sf::Sprite sp_in);
	int getKill();
	void setPosition();
	int setZycie(int zycie_in);
};
invader2::invader2(int Nt)
{
	float x = 0, y = 0;
	invader.loadFromFile("invader.png");
	N = Nt;
	invaderT = new sf::Sprite[N];
	float j[12] = { 51.0f,151.0f,251.0f,351.0f,451.0f,551.0f,651.0f,751.0f,851.0f,951.0f,1051.0f,1149.0f };
	for (int i = 0; i < N; i++)
	{

		x = j[i];
		y = 50.0f;
		invaderT[i].setTexture(invader);
		invaderT[i].setPosition(sf::Vector2f(x, y));
	}
}
void invader2::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < N; i++) {
		window.draw(invaderT[i]);
	}
}
void invader2::move2(float xVel_in, float yVel_in)
{
	xVel = xVel_in;
	yVel = yVel_in;
	for (int i = 0; i < N; i++)
	{
		sf::Vector2f position3 = invaderT[i].getPosition();
		if (position3.x <= 1150 && position3.x >= 50) {
			invaderT[i].move(xVel, yVel);

		}
		else if (position3.x > 1150)
		{
			invaderT[i].move(-1150.0, 50);
		}
		else if (position3.x < 0)
		{
			invaderT[i].move(1150.0, 50);
		}
		else
		{
			invaderT[i].move(xVel, yVel);
		}


	}

}
void invader2::sprawdzKolizje()
{
	for (int i = 0; i < N; i++) {

		sf::Vector2f position3 = invaderT[i].getPosition();
		if (position3.x <= 10)
		{
			invaderT[i].move(0, 10);
		}
		if (position3.x >= 1150)
		{
			invaderT[i].move(0, 10);
		}

		if (position3.y >= 730)
			yVel = -1;
	}
}
void invader2::getInvaders(sf::Sprite bl_in)
{
	for (int i = 0; i < N; i++)
	{
		if (invaderT[i].getGlobalBounds().intersects(bl_in.getGlobalBounds()))
		{
			invaderT[i].setPosition(10000, -10000);
			kill += 1;
		}
	}


}
int invader2::getKill() {
	for (int i = 0; i < N; i++) {
		kill = +kill;
	}
	return kill;
}
void invader2::setPosition() {
	float x = 0, y = 0;
	float j[12] = { 51.0f,151.0f,251.0f,351.0f,451.0f,551.0f,651.0f,751.0f,851.0f,951.0f,1051.0f,1149.0f };
	for (int i = 0; i < N; i++) {
		x = j[i];
		y = 50.0f;
		invaderT[i].setPosition(sf::Vector2f(x, y));
	}
}
int invader2::setZycie(int zycie_in) {
	int health = zycie_in;
	for (int i = 0; i < N; i++) {
		sf::Vector2f position = invaderT[i].getPosition();
		if (position.y > 760) {
			health -= 1;
		}
	}
	return health;
}
class interfejs
{
protected:
	sf::Vector2f ramka;
	sf::Vector2f obszarint;
	sf::RectangleShape* obszar;
	sf::Text* rt;
	sf::Text* lt;
	sf::Text* cb;
	sf::Text* rtp;
	sf::Text* fal;
	sf::Text* falnr;
	sf::Font* czcionka;
	sf::RenderWindow* windowT;
	void init();
public:
	interfejs(sf::Vector2f _ramka, sf::RenderWindow* _windowT);
	interfejs() :windowT(NULL) {}
	void setText(std::string leftT, std::string rightT, std::string centerB, std::string rtpP,std::string falP, std::string falnP);
	void draw();
};
class interfejsTekst : public interfejs
{
private:
	sf::Text* tekstGlowny;
public:
	interfejsTekst(sf::Vector2f _ramka, sf::RenderWindow* _window);
	void draw();
};

interfejsTekst::interfejsTekst(sf::Vector2f _ramka, sf::RenderWindow* _window)
{
	this->ramka = _ramka;
	this->windowT = _window;
	this->init();
	czcionka = new sf::Font;
	if (!czcionka->loadFromFile("arial.ttf"))
		return;

}
void interfejsTekst::draw()
{
	this->interfejs::draw();

	if (tekstGlowny != NULL)
	{
		windowT->draw(*tekstGlowny);
	};

}
void interfejs::init()
{
	if (ramka.x == 0 && ramka.y == 0)
		return;
	czcionka = new sf::Font;
	if (!czcionka->loadFromFile("arial.ttf"))
		return;
	lt = new sf::Text;
	rt = new sf::Text;
	cb = new sf::Text;
	rtp = new sf::Text;
	fal = new sf::Text;
	falnr = new sf::Text;
	obszar = new sf::RectangleShape;

	lt->setFont(*czcionka);
	lt->setCharacterSize(28);
	lt->setPosition(10, 5);
	lt->setFillColor(sf::Color::Cyan);
	lt->setString("Left top");

	rt->setFont(*czcionka);
	rt->setCharacterSize(28);
	rt->setPosition(100, 5);
	rt->setFillColor(sf::Color::White);
	rt->setString("Right Top");

	cb->setFont(*czcionka);
	cb->setCharacterSize(28);
	cb->setPosition(ramka.x -150, 5);
	cb->setFillColor(sf::Color::Red);
	cb->setString("Right Top");

	rtp->setFont(*czcionka);
	rtp->setCharacterSize(28);
	rtp->setPosition(ramka.x - 50, 5);
	rtp->setFillColor(sf::Color::White);
	rtp->setString("Right top Pomoc");

	fal->setFont(*czcionka);
	fal->setCharacterSize(28);
	fal->setPosition(250, 5);
	fal->setFillColor(sf::Color::Green);
	fal->setString("Right top Pomoc");

	falnr->setFont(*czcionka);
	falnr->setCharacterSize(28);
	falnr->setPosition(320, 5);
	falnr->setFillColor(sf::Color::White);
	falnr->setString("Right top Pomoc");


}
interfejs::interfejs(sf::Vector2f _ramka, sf::RenderWindow* _windowT) :ramka(_ramka), windowT(_windowT) {
	this->init();
}
void interfejs::setText(std::string leftT, std::string rightT, std::string centerB,std::string rtpP,std::string falP,std::string falnP)
{
	if (lt != NULL && rt != NULL && cb != NULL)
	{
		this->lt->setString(leftT);
		this->rt->setString(rightT);
		this->cb->setString(centerB);
		this->rtp->setString(rtpP);
		this->fal->setString(falP);
		this->falnr->setString(falnP);
	}
}
void interfejs::draw()
{
	if (lt != NULL && rt != NULL && cb != NULL && obszar != NULL)
	{
		windowT->draw(*lt);
		windowT->draw(*rt);
		windowT->draw(*cb);
		windowT->draw(*rtp);
		windowT->draw(*fal);
		windowT->draw(*falnr);
		windowT->draw(*obszar);
	}
}
class gameOver : public sf::Text {
private:
	sf::Font czcionka;
public:
	gameOver() {
		if (!czcionka.loadFromFile("arial.ttf"))
			return;
		this->setFont(czcionka);
		this->setCharacterSize(100);
		this->setPosition(300, 120);
		this->setFillColor(sf::Color::Cyan);
		this->rotate(0);
		this->setString("Game Over");
	}
};
//
//class pomoc : public sf::Text {
//private:
//	sf::Font czcionka;
//public:
//	pomoc() {
//		if (!czcionka.loadFromFile("arial.ttf"))
//			return;
//		this->setFont(czcionka);
//		this->setCharacterSize(100);
//		this->setPosition(300, 120);
//		this->setFillColor(sf::Color::Cyan);
//		this->rotate(0);
//		this->setString("Game Over");
//		this->setString("Game Over2");
//	}
//};

int main()
{
	int Nt = 12;
	int score = 0;
	int fala = 1;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Projekt infa");
	sf::Event event;
	interfejs* oknoGlowne = new interfejs(sf::Vector2f(1200.f, 800.f), &window);
	interfejsTekst* oknopomoc = new interfejsTekst(sf::Vector2f(1200.f, 800.f), &window);
	Statek pb(580, 730, window.getSize().x - 100, window.getSize().y - 100);
	pocisk bl(2000, 100);
	Player p1(0);
	gameOver(go);
	pomoc(help);
	invader2 invadery(Nt);
	sf::Clock zegar;
	sf::Clock zegar2;
	sf::Clock zegar3;
	float zegarS1=5.0f;
	float zegarS2=1.0f;
	float zegarS3=10.0f;
	int wasExectued = 0;
	int wasExectued2 = 0;
	int freeze = 0;
	int pressed = 0;
	oknopomoc->setText("Punkty: ", "koks2", "koks3","zycie","fala","fala");
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
				if (event.type == sf::Event::KeyPressed && freeze == 0)
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

				{
					if (event.key.code == sf::Keyboard::Space)
					{
						if (zegar2.getElapsedTime().asSeconds() > zegarS2 && freeze == 0)
						{
							bl.setPosition(pb.getPosition().x + 20, pb.getPosition().y + 35);
							zegar2.restart();
						}
					}
					if (event.key.code == sf::Keyboard::Escape) {
						freeze = 0;
					}

				}
			case sf::Event::KeyReleased:
				if (event.key.code==sf::Keyboard::F1) {
					
					pressed = 1;
						freeze = 1;
				}
			}
		}
		int someint = invadery.getKill();
		char str[12];
		int someint2 = invadery.setZycie(3);
		char str2[12];
		char str3[12];
		sprintf(str3, "%d", fala);
		sprintf(str2, "%d", someint2);
		sprintf(str, "%d", someint);
		oknopomoc->setText("Score: ", str, "Health: ",str2,"Fala: ",str3);
		p1.setScore(invadery.getKill());
		window.clear(sf::Color::Black);
		window.draw(pb.getStatek());
		window.draw(bl.getPocisk());
		if (pressed == 1 && freeze==1)
		{
			window.draw(go);
		}
		invadery.draw(window);
		if (wasExectued == fala-1 && p1.getScore() == Nt*fala) {
			wasExectued = fala;
			invadery.setPosition();
			fala++;
		}
		oknopomoc->draw();
		if (zegar.getElapsedTime().asMilliseconds() > zegarS1 && freeze == 0)
		{
			bl.animuj();
			zegar.restart();

		}
		if (zegar3.getElapsedTime().asMilliseconds() > zegarS3 && freeze == 0) {
			invadery.move2(1*fala, 0);
			
			invadery.getInvaders(bl.getPocisk());
			zegar3.restart();
		}
	
		window.display();
		
	}
	printf("%d", invadery.setZycie(3));
	p1.drawScore();
	return 0;
}