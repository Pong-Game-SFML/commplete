#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayWindow
{
private:
	int WIDTH = 1000;
	int HEIGHT = 800;
	Font font_Score;
	Text text[2];
	Font font_Speed;
	Text speed;
public:
	string playGameTwoPlayer(string name1, string name2);

	string playGameOnePlayer(string name);

	void Winer(string name);

};
