#ifndef ACTIONS_H__
#define ACTIONS_H__

#include <SFML/Graphics.hpp>

#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class Actions
{
	MinesweeperBoard& board;
	MSSFMLView& view;
	sf::RenderWindow win;
	sf::Event event;
	int row;
	int col;
	int x;
	int y;

public:
	Actions(MinesweeperBoard& board, sf::Event event, MSSFMLView& view);
	void lmbPressed() const;
	void rmbPressed() const;
	void addEvents() const;
};

#endif