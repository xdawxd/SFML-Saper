#ifndef ACTIONS_H__
#define ACTIONS_H__

#include <SFML/Graphics.hpp>

#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class Actions
{
	MinesweeperBoard& board;
	MSSFMLView& view;

public:
	Actions(MinesweeperBoard& board, MSSFMLView& view);
	void lmbPressed(sf::Event& event) const;
	void rmbPressed(sf::Event& event) const;
	void addEvents(sf::Event& event) const;
};

#endif