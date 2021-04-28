#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__

#include <SFML/Graphics.hpp>

#include "MinesweeperBoard.h"

class MSSFMLView
{
	int height;
	int width;
	int screen_height;
	int screen_width;
	GameMode mode;
	GameState state;
	MinesweeperBoard& displayableBoard;
	sf::RectangleShape addShadow(sf::RectangleShape field);
	void drawNumber(sf::RenderWindow& win, char number, int x, int y);
	void displayInfo(GameState state, sf::Font font, sf::RenderWindow& win);

public:
	MSSFMLView(MinesweeperBoard& board);
	void draw(sf::RenderWindow& win);
	void clearMovesCounter();
	void floodFill(int row, int col);
};

#endif