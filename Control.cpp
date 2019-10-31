#include "Control.h"

void Control :: processGame()
{
	cBeginMenu begin(WIDTH, HEIGHT);

	RenderWindow beginWindow(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	Event event;
	while (beginWindow.isOpen())
	{
		while (beginWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				beginWindow.close();
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard ::Up)
				{
					begin.moveUp();
				}
				else if (event.key.code == Keyboard::Up)
				{
					begin.moveDown();
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			begin.moveUp();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			begin.moveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			beginWindow.close();
		}
		

		beginWindow.clear();
		begin.draw(beginWindow);
		beginWindow.display();
	}
}