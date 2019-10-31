#include "cEndMenu.h"
using namespace std;
cEndMenu::cEndMenu()
{
	
}

void cEndMenu :: setUpEndMenu(int width, int height)
{
	Font font;
	font.loadFromFile("Leoscar Sans Serif.ttf"); //font chu cua cac tuy chon

	text[0].setFont(font);
	text[0].setPosition(445, 333);
	text[0].setCharacterSize(40);
	text[0].setFillColor(Color::Green);
	text[0].setString("PLAY AGAIN");

	text[1].setFont(font);
	text[1].setPosition(435, 433);
	text[1].setCharacterSize(40);
	text[1].setFillColor(Color::White);
	text[1].setString("HIGH SCORES");

	text[2].setFont(font);
	text[2].setPosition(510, 533);
	text[2].setCharacterSize(40);
	text[2].setFillColor(Color::White);
	text[2].setString("EXIT");

	box[0].setPosition(400, 330);
	box[0].setFillColor(Color::Transparent);
	box[0].setSize(Vector2f(280, 60));
	box[0].setOutlineColor(Color::Green);
	box[0].setOutlineThickness(5);

	box[1].setPosition(400, 430);
	box[1].setFillColor(Color::Transparent);
	box[1].setSize(Vector2f(280, 60));
	box[1].setOutlineColor(Color::White);
	box[1].setOutlineThickness(5);

	box[2].setPosition(400, 530);
	box[2].setFillColor(Color::Transparent);
	box[2].setSize(Vector2f(280, 60));
	box[2].setOutlineColor(Color::White);
	box[2].setOutlineThickness(5);

	selectItem = 0;
}

void cEndMenu::drawEndMenu(RenderWindow& window)
{
	for (int i = 0; i < OBJECTS; i++)
	{
		window.draw(box[i]);
		window.draw(text[i]);
	}
}

void cEndMenu::moveUp()
{
	if (selectItem - 1 >= 0)
	{
		text[selectItem].setColor(Color::White);
		box[selectItem].setOutlineColor(Color::White);
		selectItem--;
		text[selectItem].setColor(Color::Green);
		box[selectItem].setOutlineColor(Color::Green);
	}
}

void cEndMenu::moveDown()
{
	if (selectItem + 1 < OBJECTS)
	{
		text[selectItem].setColor(Color::White);
		box[selectItem].setOutlineColor(Color::White);
		selectItem++;
		text[selectItem].setColor(Color::Green);
		box[selectItem].setOutlineColor(Color::Green);
	}
}

int cEndMenu::getChoose()
{
	return selectItem;
}

void cEndMenu::controlEndMenu()
{
	int WIDTH = 1024;
	int HEIGHT = 768;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	//tao background cho man hinh menu
	Texture texture;
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	//In tieu de menu
	Font font;
	font.loadFromFile("Facon.ttf");
	Text title("GAME OVER", font);
	title.setPosition(200, 150);
	title.setCharacterSize(100);
	title.setFillColor(Color(26, 58, 175, 255));

	setUpEndMenu(WIDTH, HEIGHT);

	Event event;

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					moveUp();
					break;
				case Keyboard::Down:
					moveDown();
					break;
				case Keyboard::Return:
					switch (getChoose())
					{
					case 0:
					{
						cout << "Play again" << endl;
					}
						break;
					case 1:
						cout << "Show highscores button" << endl;
						break;
					case 2:
						window.close();
						break;
					}
				}
				break;
			}

		}
		window.draw(sprite);
		drawEndMenu(window);
		window.draw(title);
		window.display();

	}

}

void cEndMenu :: highScore()
{
	Font font;
	font.loadFromFile("Rainbow Colors - TTF.ttf");

	RenderWindow window(VideoMode(1024, 768), "Ping Pong Game");
	
	Event event;
	
	Text title("HIGH SCORE", font, 50);
	title.setFillColor(Color(250, 250, 20));
	title.setOutlineColor(Color(0, 0, 0));
	title.setOutlineThickness(10);
	title.setPosition(400, 0);

	Texture texture;
	texture.loadFromFile("highscore.jpg");
	Sprite sprite(texture);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear(Color::Black);
		window.draw(sprite);
		window.draw(title);
		window.display();
	}
}
