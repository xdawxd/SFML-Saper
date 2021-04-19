#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MinesweeperBoard.h"

class MSSFMLView
{
	int height;
	int width;
	int screen_height;
	int screen_width;
	sf::Color numberColor(sf::Text text);
	sf::RectangleShape shadow(sf::RectangleShape rec, sf::Color color);
	MinesweeperBoard& displayableBoard;

public:
	MSSFMLView(MinesweeperBoard& board);
	void draw(sf::RenderWindow& win);
};

#endif
