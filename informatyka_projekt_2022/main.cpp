#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define max_menu_items 4
class Player {
private:
	int score = 0;
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
	void sterowanie();
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
void Statek::sterowanie() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		przesun(-0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		przesun(0.1, 0);
	}

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
	pos.x = 0;
	pSprite2.move(pos);
}
void pocisk::setPosition(float x_in, float y_in)
{
	position2.x = x_in;
	position2.y = y_in;
	pSprite2.setPosition(position2);
}
class invader2 {
private:
	sf::Texture invader;
	sf::Sprite* invaderT;
	int N;
	float xVel = 1, yVel = 0;
	int kill = 0;
	int przeszlo = 0;
public:

	invader2(int N);
	void draw(sf::RenderWindow& window);
	void move2(float xVel_in, float yVel_in);
	void sprawdzKolizje();
	void getInvaders(sf::Sprite sp_in);
	int getKill();
	void setPosition();
	int setZycie(int zycie_in);
	int getprzeszlo();
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
int invader2::getprzeszlo() {
	for (int i = 0; i < N; i++) {
		przeszlo = +przeszlo;
	}
	return przeszlo;
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
		if (position.y > 700) {
			health -= 1;
			przeszlo = 1;
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
	void setText(std::string leftT, std::string rightT, std::string centerB, std::string rtpP, std::string falP, std::string falnP);
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
	if (!czcionka->loadFromFile("arcade.ttf"))
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
	if (!czcionka->loadFromFile("arcade.ttf"))
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
	cb->setPosition(ramka.x - 150, 5);
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
void interfejs::setText(std::string leftT, std::string rightT, std::string centerB, std::string rtpP, std::string falP, std::string falnP)
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
class help {
private:
	sf::Font czcionka;
	sf::Text menu[5];
	sf::Sprite ramka2;
	sf::Texture tekstura;
public:
	help(float width_in, float height_in);
	~help();

	void draw(sf::RenderWindow& window);
};
help::help(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf"))
		return;


	menu[0].setFont(czcionka);
	menu[0].setCharacterSize(25);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("[A] - poruszanie statkiem w lewo");
	menu[0].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 1) * 2));

	tekstura.loadFromFile("ramka.png");
	ramka2.setTexture(tekstura);
	ramka2.setPosition(330, 00);

	menu[1].setFont(czcionka);
	menu[1].setCharacterSize(28);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("[D] - poruszanie statkiem w prawo");
	menu[1].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 2) * 3));

	menu[2].setFont(czcionka);
	menu[2].setCharacterSize(28);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("[SPACE] - strzal");
	menu[2].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 2.5) * 4));



	menu[3].setFont(czcionka);
	menu[3].setCharacterSize(28);
	menu[3].setFillColor(sf::Color::Green);
	menu[3].setString("[ESC] - wroc do gry");
	menu[3].setPosition(sf::Vector2f(width_in / 2 - 150, height_in / (4 + 1) * 4));

	menu[4].setFont(czcionka);
	menu[4].setCharacterSize(25);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Zniszcz jak najwiecej przeciwnikow \nzanim osiagna cel \n swojej trasy, powstrzymaj ich, \n przed dotarciem na sam dol!");
	menu[4].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 1) * 1));
}
help::~help() {

}
void help::draw(sf::RenderWindow& window)
{
	window.draw(ramka2);
	for (int i = 0; i < 5; i++) {
		window.draw(menu[i]);
	}
}
class Menu {
private:
	int selectedItem;
	sf::Font czcionka;
	sf::Text opcja[max_menu_items];
	sf::Sprite ramka2;
	sf::Texture tekstura;
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void mUp();
	void mDwn();
	int getPressedItem() { return selectedItem; }
};
Menu::Menu(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf")) {
		return;
	}
	opcja[0].setFont(czcionka);
	opcja[0].setFillColor(sf::Color::Red);
	opcja[0].setString("Start");
	opcja[0].setPosition(sf::Vector2f(width_in / 2 - 50, height_in / (max_menu_items + 1) * 1));

	opcja[1].setFont(czcionka);
	opcja[1].setFillColor(sf::Color::White);
	opcja[1].setString("Ostatnie gry");
	opcja[1].setPosition(sf::Vector2f(width_in / 2 - 50, height_in / (max_menu_items + 1) * 2));

	opcja[2].setFont(czcionka);
	opcja[2].setFillColor(sf::Color::White);
	opcja[2].setString("Pomoc");
	opcja[2].setPosition(sf::Vector2f(width_in / 2 - 50, height_in / (max_menu_items + 1) * 3));

	opcja[3].setFont(czcionka);
	opcja[3].setFillColor(sf::Color::White);
	opcja[3].setString("Wyjscie");
	opcja[3].setPosition(sf::Vector2f(width_in / 2 - 50, height_in / (max_menu_items + 1) * 4));
	selectedItem = 0;

	tekstura.loadFromFile("ramka.png");
	ramka2.setTexture(tekstura);
	ramka2.setPosition(330, 00);
}
Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(ramka2);
	for (int i = 0; i < max_menu_items; i++) {
		window.draw(opcja[i]);
	}
}
void Menu::mUp() {
	if (selectedItem - 1 >= 0) {
		opcja[selectedItem].setFillColor(sf::Color::White);
		selectedItem = selectedItem - 1;
		opcja[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Menu::mDwn() {
	if (selectedItem + 1 < max_menu_items) {
		opcja[selectedItem].setFillColor(sf::Color::White);
		selectedItem = selectedItem + 1;
		opcja[selectedItem].setFillColor(sf::Color::Red);
	}
}



class background {
private:
	sf::Sprite tlo;
	sf::Texture tlotex;
public:
	background(int nm);
	void draw(sf::RenderWindow& window);
};
background::background(int nm) {
	tlotex.loadFromFile("background.png");
	tlo.setTexture(tlotex);
	tlo.setPosition(0, 0);
}
void background::draw(sf::RenderWindow& window) {
	window.draw(tlo);
}
void players_to_file(char* text_in, int score_in)
{
	int score = score_in;
	FILE* fp;
	fp = fopen("gracze.txt", "a");
	fputs(text_in, fp);
	fprintf(fp, "%d \n", score);
	fclose(fp);
}
class playerszap {
private:
	sf::Text players[10];
	sf::Font czcionka;
	std::string graczrank[100];
public:
	playerszap(float width_in, float height_in);
	void readfile();
	void setPlayers();
	void drawPlayers(sf::RenderWindow& window);
	void wyczysc();
};
playerszap::playerszap(float width_in, float height_in) {
	for (int i = 0; i < 10; i++) {
		players[i].setFont(czcionka);
		players[i].setCharacterSize(30);
		players[i].setFillColor(sf::Color::Red);
	}
}
void playerszap::readfile() {
	std::ifstream gracze("gracze.txt", std::ios::app);

	for (int i = 0; i < 100; i++) {
		gracze >> graczrank[i];
		if (graczrank[i] == "") {
			graczrank[i] = "BRAK";
		}
	}
	gracze.close();
}
void playerszap::setPlayers() {
	czcionka.loadFromFile("arcade.ttf");
	for (int i = 0; i < 10; i++) {
		players[i].setString(graczrank[i]);
		players[i].setFont(czcionka);
		players[i].setCharacterSize(30);
		players[i].setFillColor(sf::Color::Red);
		if (i % 2 == 0 || i == 0) {
			players[i].setPosition(1200 / 2 - 250, 800 / (5 + 1) * i / 2 + 100);
		}
		else if (i % 2 != 0)
		{
			players[i].setPosition(1200 / 2 + 250, 800 / (5 + 1) * (i - 1) / 2 + 100);
		}

	}
}
void playerszap::drawPlayers(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++) {
		window.draw(players[i]);
	}
}
void playerszap::wyczysc() {
	FILE* fp;
	fp = fopen("gracze.txt", "w+");
	fclose(fp);
}
class menuz {
private:
	sf::Font czcionka;
	sf::Text menu[13];
	sf::Sprite ramka2;
	sf::Texture tekstura;
	int selectedItem;
public:
	menuz(float width_in, float height_in);
	~menuz();

	void draw(sf::RenderWindow& window);
};
menuz::menuz(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf"))
		return;


	menu[11].setFont(czcionka);
	menu[11].setCharacterSize(30);
	menu[11].setFillColor(sf::Color::White);
	menu[11].setString("Ostatnie gry");
	menu[11].setPosition(sf::Vector2f(400, 15));

	menu[0].setFont(czcionka);
	menu[0].setCharacterSize(30);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("1. Nazwa: ");
	menu[0].setPosition(sf::Vector2f(width_in / 2 - 400, 800 / (5 + 1) * 0 / 2 + 100));

	menu[1].setFont(czcionka);
	menu[1].setCharacterSize(30);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Punkty: ");
	menu[1].setPosition(sf::Vector2f(width_in / 2 + 20, height_in / (5 + 1) * 0 / 2 + 100));

	menu[2].setFont(czcionka);
	menu[2].setCharacterSize(30);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("2. Nazwa: ");
	menu[2].setPosition(sf::Vector2f(width_in / 2 - 400, height_in / (5 + 1) * 1 + 100));

	menu[3].setFont(czcionka);
	menu[3].setCharacterSize(30);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Punkty: ");
	menu[3].setPosition(sf::Vector2f(width_in / 2 + 20, height_in / (5 + 1) * 1 + 100));

	menu[4].setFont(czcionka);
	menu[4].setCharacterSize(30);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("3. Nazwa: ");
	menu[4].setPosition(sf::Vector2f(width_in / 2 - 400, height_in / (5 + 1) * 2 + 100));

	menu[5].setFont(czcionka);
	menu[5].setCharacterSize(30);
	menu[5].setFillColor(sf::Color::White);
	menu[5].setString("Punkty: ");
	menu[5].setPosition(sf::Vector2f(width_in / 2 + 20, height_in / (5 + 1) * 2 + 100));

	menu[6].setFont(czcionka);
	menu[6].setCharacterSize(30);
	menu[6].setFillColor(sf::Color::White);
	menu[6].setString("4. Nazwa: ");
	menu[6].setPosition(sf::Vector2f(width_in / 2 - 400, height_in / (5 + 1) * 3 + 100));

	menu[7].setFont(czcionka);
	menu[7].setCharacterSize(30);
	menu[7].setFillColor(sf::Color::White);
	menu[7].setString("Punkty: ");
	menu[7].setPosition(sf::Vector2f(width_in / 2 + 20, height_in / (5 + 1) * 3 + 100));

	menu[8].setFont(czcionka);
	menu[8].setCharacterSize(30);
	menu[8].setFillColor(sf::Color::White);
	menu[8].setString("5. Nazwa: ");
	menu[8].setPosition(sf::Vector2f(width_in / 2 - 400, height_in / (5 + 1) * 4 + 100));

	menu[9].setFont(czcionka);
	menu[9].setCharacterSize(30);
	menu[9].setFillColor(sf::Color::White);
	menu[9].setString("Punkty: ");
	menu[9].setPosition(sf::Vector2f(width_in / 2 + 20, height_in / (5 + 1) * 4 + 100));

	menu[10].setFont(czcionka);
	menu[10].setCharacterSize(26);
	menu[10].setFillColor(sf::Color::Green);
	menu[10].setString("Wcisnij [ESC] aby wrocic do menu");
	menu[10].setPosition(sf::Vector2f(1200 / 2 - 400, 760));

	menu[12].setFont(czcionka);
	menu[12].setCharacterSize(26);
	menu[12].setFillColor(sf::Color::Green);
	menu[12].setString("Wcisnij [F2] aby wyczyscic historie");
	menu[12].setPosition(sf::Vector2f(1200 / 2 + 20, 760));
}
menuz::~menuz() {

}
void menuz::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 13; i++) {
		window.draw(menu[i]);
	}
}
class poz {
private:
	sf::Font czcionka;
	sf::Text menu[4];
	sf::Sprite ramka2;
	sf::Texture tekstura;
	int selectedItem;
public:
	poz(float width_in, float height_in);
	~poz();

	void draw(sf::RenderWindow& window);
	void mUp();
	void mDwn();
	int getPressedItem() { return selectedItem; }
};
poz::poz(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf"))
		return;


	menu[0].setFont(czcionka);
	menu[0].setCharacterSize(25);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Wybierz poziom trudnosci");
	menu[0].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4) * 1));

	tekstura.loadFromFile("ramka.png");
	ramka2.setTexture(tekstura);
	ramka2.setPosition(330, 00);

	menu[1].setFont(czcionka);
	menu[1].setCharacterSize(28);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("Poziom latwy");
	menu[1].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 2) * 2));

	menu[2].setFont(czcionka);
	menu[2].setCharacterSize(28);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Poziom normalny");
	menu[2].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 3) * 3));



	menu[3].setFont(czcionka);
	menu[3].setCharacterSize(28);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Poziom trudny");
	menu[3].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4 + 3.5) * 4));
	selectedItem = 1;
}
poz::~poz() {

}
void poz::draw(sf::RenderWindow& window)
{
	window.draw(ramka2);
	for (int i = 0; i < 4; i++) {
		window.draw(menu[i]);
	}
}

void poz::mUp() {
	if (selectedItem - 1 >= 1) {
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem = selectedItem - 1;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
void poz::mDwn() {
	if (selectedItem + 1 < 4) {
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem = selectedItem + 1;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

class gameo {
private:
	sf::Font czcionka;
	sf::Text menu[1];
	sf::Sprite ramka2;
	sf::Texture tekstura;
public:
	gameo(float width_in, float height_in);
	~gameo();

	void draw(sf::RenderWindow& window);
};
gameo::gameo(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf"))
		return;


	menu[0].setFont(czcionka);
	menu[0].setCharacterSize(25);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Koniec gry, podaj swoje imie \n aby zapisac wynik:");
	menu[0].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (4) * 1));

	tekstura.loadFromFile("ramka.png");
	ramka2.setTexture(tekstura);
	ramka2.setPosition(330, 00);
}
gameo::~gameo() {

}
void gameo::draw(sf::RenderWindow& window)
{
	window.draw(ramka2);
	for (int i = 0; i < 1; i++) {
		window.draw(menu[i]);
	}
}
class wyjsc {
private:
	sf::Font czcionka;
	sf::Text menu[3];
	sf::Sprite ramka2;
	sf::Texture tekstura;
public:
	wyjsc(float width_in, float height_in);
	~wyjsc();

	void draw(sf::RenderWindow& window);
};
wyjsc::wyjsc(float width_in, float height_in) {
	if (!czcionka.loadFromFile("arcade.ttf"))
		return;


	menu[0].setFont(czcionka);
	menu[0].setCharacterSize(30);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Gra wstrzymana");
	menu[0].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (3+1) * 1));

	menu[1].setFont(czcionka);
	menu[1].setCharacterSize(30);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("Aby wyjsc wcisnij [Enter]");
	menu[1].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (3+1) * 2));

	menu[2].setFont(czcionka);
	menu[2].setCharacterSize(30);
	menu[2].setFillColor(sf::Color::Green);
	menu[2].setString("Aby kontynuowac wcisnij [F4]");
	menu[2].setPosition(sf::Vector2f(width_in / 2 - 200, height_in / (3+1) * 3));


	tekstura.loadFromFile("ramka.png");
	ramka2.setTexture(tekstura);
	ramka2.setPosition(330, 00);
}
wyjsc::~wyjsc() {

}
void wyjsc::draw(sf::RenderWindow &window) {
	window.draw(ramka2);
	for (int i = 0; i < 3; i++) {
		window.draw(menu[i]);
	}
}
int main()
{
	int Nt = 12;
	int score = 0;
	int fala = 1;
	int trudnosc = 1;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Projekt infa");
	sf::Event event;
	interfejs* oknoGlowne = new interfejs(sf::Vector2f(1200.f, 800.f), &window);
	interfejsTekst* oknopomoc = new interfejsTekst(sf::Vector2f(1200.f, 800.f), &window);
	Statek pb(580, 730, window.getSize().x - 100, window.getSize().y - 100);
	pocisk bl(2000, -10);
	Player p1(0);
	playerszap playz(window.getSize().x, window.getSize().y);
	Menu menu(window.getSize().x, window.getSize().y);
	help help(window.getSize().x, window.getSize().y);
	poz poz(window.getSize().x, window.getSize().y);
	gameo gameo(window.getSize().x, window.getSize().y);
	menuz menuz(window.getSize().x, window.getSize().y);
	wyjsc wyjsc(window.getSize().x, window.getSize().y);
	invader2 invadery(Nt);
	background tlo(0);
	sf::Clock zegar;
	sf::Clock zegar2;
	sf::Clock zegar3;
	sf::Font czcion;
	czcion.loadFromFile("arcade.ttf");
	sf::String playerInput;
	sf::Text playerText("", czcion, 25);
	playerText.setPosition(1200 / 2 - 200, 800 / (4 - 1) * 1);
	playerText.setFillColor(sf::Color::Red);
	float zegarS1 = 5.0f;
	float zegarS2 = 1.0f;
	float zegarS3 = 10.0f;
	int wasExectued = 0;
	int wasExectued2 = 0;
	int freeze = 1;
	int m = 1;
	int h = 0;
	int p = 0;
	int go = 0;
	int drukuj = 0;
	int czyszcz = 0;
	int pressed = 0;
	int wyj = 0;
	oknopomoc->setText("", "", "", "", "", "");
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
			case sf::Event::KeyReleased:
				if (event.type == sf::Event::KeyReleased && m == 1 && p == 0)
				{
					if (event.key.code == sf::Keyboard::Up) {
						menu.mUp();
					}
					if (event.key.code == sf::Keyboard::Down) {
						menu.mDwn();
					}
					if (event.key.code == sf::Keyboard::Return && wyj == 0) {
						switch (menu.getPressedItem()) {
						case 0:
							m = 0;
							p = 1;
							break;
						case 1:
							m = 0;
							drukuj = 1;
							break;
						case 2:
							h = 1;
							m = 0;
							break;
						case 3:
							window.close();
							break;
						}

					}

				}
				else if (event.type == sf::Event::KeyReleased && m == 0 && p == 1) {
					if (event.key.code == sf::Keyboard::Up && m == 0 && p == 1) {
						poz.mUp();
					}
					if (event.key.code == sf::Keyboard::Down && m == 0 && p == 1) {
						poz.mDwn();
					}
					if (event.key.code == sf::Keyboard::Return && m == 0 && p == 1 && wyj == 0) {
						switch (poz.getPressedItem()) {
						case 1:
							trudnosc = 1;
							freeze = 0;
							p = 0;
							break;
						case 2:
							trudnosc = 2;
							freeze = 0;
							p = 0;
							break;
						case 3:
							trudnosc = 3;
							freeze = 0;
							p = 0;
							break;
						}
					}

				}
				if (event.key.code == sf::Keyboard::F1 && m == 0 && freeze == 0) {
					h = 1;
					freeze = 1;
					pressed = 1;
				}
				if (event.key.code == sf::Keyboard::Escape && m == 0 && freeze == 1 && h == 1 && pressed == 0) {
					h = 0;
					m = 1;
				}
				if (event.key.code == sf::Keyboard::Escape && m == 0 && freeze == 1 && h == 1 && pressed == 1) {
					h = 0;
					m = 0;
					freeze = 0;
					pressed = 0;
				}
				if (event.key.code == sf::Keyboard::Escape && m == 0 && freeze == 1 && drukuj == 1) {
					drukuj = 0;
					m = 1;
				}

				if (event.key.code == sf::Keyboard::F2 && m == 0 && freeze == 1 && drukuj == 1) {
					czyszcz = 1;
					m = 1;
					freeze = 1;
					drukuj = 0;
				}
				if (event.key.code == sf::Keyboard::F3 && wyj==0) {
					wyj = 1;
					freeze = 1;
				}
				if (event.key.code == sf::Keyboard::Return && wyj == 1) {
					window.close();
					wyj = 0;
				}
				if (event.key.code == sf::Keyboard::F4 && wyj==1)
				{
					freeze = 0;
					wyj = 0;
				}

				if (event.key.code == sf::Keyboard::Return && go == 1 && wyj == 0) {
					std::string ok = playerText.getString();
					char tekst[10];
					strcpy(tekst, ok.c_str());
					players_to_file(tekst, p1.getScore());
					drukuj = 1;
					freeze = 1;
					window.close();
				}

				if (event.key.code == sf::Keyboard::Escape && drukuj == 1) {
					drukuj = 0;
					m = 1;
					go = 0;
					freeze = 1;
				}

			}
			if (event.type == sf::Event::TextEntered && go == 1)
			{
				playerInput += event.text.unicode;
				playerText.setString(playerInput);
				
			}
		}
		int someint = invadery.getKill();
		char str[12];
		int someint2 = invadery.setZycie(1);
		char str2[12];
		char str3[12];
		sprintf(str3, "%d", fala);
		sprintf(str2, "%d", someint2);
		sprintf(str, "%d", someint);

		window.clear();

		tlo.draw(window);
		if (m == 0 && h == 0 && freeze == 0) {
			tlo.draw(window);
			window.draw(pb.getStatek());
			window.draw(bl.getPocisk());
			oknopomoc->draw();
			oknopomoc->setText("Score: ", str, "Health: ", str2, "Fala: ", str3);
			p1.setScore(invadery.getKill());
			invadery.draw(window);

		}
		if (p == 1) {
			poz.draw(window);
		}
		pb.sterowanie();
		if (m == 1 && h == 0) { menu.draw(window); }
		if (freeze == 1 && h == 1)
		{
			tlo.draw(window);
			help.draw(window);

		}

		if (wasExectued == fala - 1 && p1.getScore() == Nt * fala) {
			wasExectued = fala;
			invadery.setPosition();
			fala++;
		}
		else if (wasExectued == fala - 1 && p1.getScore() + invadery.setZycie(1) + 1 == Nt * fala && invadery.getprzeszlo() > 0) {
			wasExectued = fala;
			invadery.setPosition();
			fala++;
		}

		if (zegar.getElapsedTime().asMilliseconds() > zegarS1 && freeze == 0 && m == 0 && h == 0)
		{
			bl.animuj();
			zegar.restart();

		}
		if (zegar3.getElapsedTime().asMilliseconds() > zegarS3 && freeze == 0 && m == 0) {
			invadery.move2(1.5 * fala * trudnosc, 0);

			invadery.getInvaders(bl.getPocisk());
			zegar3.restart();
		}
		if (zegar2.getElapsedTime().asSeconds() > zegarS2 && freeze == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bl.setPosition(pb.getPosition().x + 20, pb.getPosition().y + 35);
			zegar2.restart();
		}
		if (h == 1 && m == 0) {
			tlo.draw(window);
			help.draw(window);

		}
			
		if (invadery.setZycie(1) < 0 && m == 0 && h==0)
		{
			go = 1;
			freeze = 1;
			tlo.draw(window);
			window.draw(playerText);
			gameo.draw(window);
		}
		if (drukuj == 1) {
			tlo.draw(window);
			playz.readfile();
			playz.setPlayers();
			playz.drawPlayers(window);
			menuz.draw(window);

		}
		if (czyszcz == 1) {
			playz.wyczysc();
		}
		if (wyj == 1) {
			tlo.draw(window);
			wyjsc.draw(window);
		}
		window.display();
	}
	return 0;
}