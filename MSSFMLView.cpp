#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard& board) : displayableBoard(board)
{
	height = board.getBoardHeight();
	width = board.getBoardWidth();
}

void MSSFMLView::draw(sf::RenderWindow& win)
{
	GameState state = displayableBoard.getGameState();
	sf::RectangleShape field(sf::Vector2f(35, 35));
	field.setFillColor(sf::Color::White);
	int screen_height = win.getSize().x;
	int screen_width = win.getSize().y;

	int space_height = 65;
	int space_width = 55;

	for (int row = 0; row < height; ++row)
	{
		for (int col = 0; col < width; ++col)
		{
			field.setPosition((screen_height / height) +  row * space_height, (screen_width / width) + col * space_width);
			win.draw(field);
		}
	}

	//field.setPosition((screen_height / 4) + 0 * space, (screen_width / 3) + 0 * space);
	//win.draw(field);
}

