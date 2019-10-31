#include "cPlayWindow.h"
string cPlayWindow::playGameTwoPlayer(string name1, string name2)
{
	string kq = "";
	cBall ball(550, 400);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);
	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	font_Score.loadFromFile("Facon.ttf");

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	
	text[0].setCharacterSize(100);
	text[0].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[0].setPosition(200, 50);
	text[0].setFont(font_Score);

	text[1].setCharacterSize(100);
	text[1].setFillColor(Color(238, 238, 5));
	text[1].setOutlineColor(Color::Red);
	text[1].setOutlineThickness(-5);
	text[1].setPosition(700, 50);
	text[1].setFont(font_Score);

	font_Speed.loadFromFile("BABYK___.TTF");
	speed.setFont(font_Speed);
	speed.setFillColor(Color(150,20,150));
	speed.setOutlineColor(Color(150,150,200));
	speed.setOutlineThickness(10);
	speed.setPosition(400, 700);

	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close(); //neu bam dau tat tren man hinh thi cua so tat
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			// move up...
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			// move up
			paddle1.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			// move up
			paddle1.moveDown(HEIGHT);
		}

		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		int Win = ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.update();
		paddle2.update();

		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);
		window.draw(speed);

		window.draw(ball.getShape());

		window.display();
		if (Win == 1)
		{
			window.close();
			kq = name1+ " "  + scorePlayer1;
		}
		else if (Win == 2)
		{
			window.close();
			kq = name2+ " " + scorePlayer2;
		}
	}
	return kq;
}


string cPlayWindow::playGameOnePlayer(string name)
{
	string kq = "";

	cBall ball(550, 400);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);

	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	font_Score.loadFromFile("Facon.ttf");

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	text[0].setCharacterSize(100);
	text[0].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[0].setPosition(200, 50);
	text[0].setFont(font_Score);

	text[1].setCharacterSize(100);
	text[1].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[1].setPosition(700, 50);
	text[1].setFont(font_Score);

	font_Speed.loadFromFile("BABYK___.TTF");
	speed.setFont(font_Speed);
	speed.setFillColor(Color(150, 20, 150));
	speed.setOutlineColor(Color(150, 150, 200));
	speed.setOutlineThickness(10);
	speed.setPosition(400, 700);

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close(); //neu bam dau tat tren man hinh thi cua so tat
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			// move up...
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}

		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);

		int Win=ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.autoMove(0, HEIGHT, ball);

		paddle1.update();
		paddle2.update();

		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		window.draw(ball.getShape());

		window.display();

		if (Win == 1)
		{
			kq = "Computer " + scorePlayer1;
			window.close();
		}
		else if (Win == 2)
		{
			kq = name +" " + scorePlayer1;
			window.close();
		}
	}
}


void cPlayWindow :: Winer(string name)
{
	/*Texture texture;
	texture.loadFromFile("galaxy-wallpaper-11.jpg");
	Sprite sprite(texture);*/

	Font font;
	font.loadFromFile("BARBATRI.TTF");

	Text text[4];
	
	text[0].setCharacterSize(50);
	text[0].setFont(font);
	text[0].setFillColor(Color(223, 0, 41));
	text[0].setString("THE WINER IS");
	text[0].setPosition(370, 20);

	font.loadFromFile("Rainbow Colors - TTF.ttf");
	text[1].setCharacterSize(100);
	text[1].setFont(font);
	text[1].setFillColor(Color(223, 0, 41));
	text[1].setOutlineColor(Color(12,178,192));
	text[1].setOutlineThickness(10);
	text[1].setString(name);
	text[1].setPosition(WIDTH / 2 - text[1].getLocalBounds().width / 2, 150);
	
	font.loadFromFile("Cucho Bold.otf");
	text[2].setCharacterSize(30);
	text[2].setFont(font);
	text[2].setFillColor(Color(223, 0, 41));
	text[2].setString("Press Enter to replay!");
	text[2].setPosition(350, 350);

	text[3].setCharacterSize(30);
	text[3].setFont(font);
	text[3].setFillColor(Color(223, 0, 41));
	text[3].setString("Press ESC to quit the game!");
	text[3].setPosition(320, 450);

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	
	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			window.close();
		}

		window.clear(Color(120,250,200));
		for (int i = 0;i < 4;i++)
		{
			window.draw(text[i]);
		}
		window.display();
	}
}