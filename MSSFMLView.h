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
	GameMode mode;
	MinesweeperBoard& displayableBoard;
	sf::RectangleShape addShadow(sf::RectangleShape field);
	sf::Text displayText(std::string str, int fontSize, sf::Font font, sf::RectangleShape& rect);
	void createClock();
	sf::RectangleShape createNewGameBox();
	sf::RectangleShape createDifficultues();
	sf::RectangleShape authorBox();

public:
	MSSFMLView(MinesweeperBoard& board);
	void draw(sf::RenderWindow& win);
};

#endif