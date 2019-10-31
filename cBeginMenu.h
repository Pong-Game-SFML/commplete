#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace sf;
#define OBJECTS 3

class cBeginMenu
{
private:
	int selectItem;
	Font font;
	RectangleShape box[OBJECTS];
	Text text[OBJECTS];

public:
	cBeginMenu(int width, int height);

	void draw(RenderWindow &window);

	void moveUp();

	void moveDown();

	int getChoose();

};

