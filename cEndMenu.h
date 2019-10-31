#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace sf;
using namespace std;

#define OBJECTS 3

class cEndMenu
{
private:
	int selectItem;
	RectangleShape box[OBJECTS];
	Text text[OBJECTS];

public:
	cEndMenu(); // doi thanh ham set up end menu

	void setUpEndMenu(int WIDTH, int HEIGHT);

	// moi doi ten tu draw thanh drawEndMenu
	void drawEndMenu(RenderWindow& window);//ve end menu len man hinh 

	void moveUp();

	void moveDown();

	int getChoose(); //tra ve lua chon trong menu

	void controlEndMenu();
	
	void highScore();
};
