#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard& board) : displayableBoard(board)
{
	height = board.getBoardHeight();
	width = board.getBoardWidth();
}

void MSSFMLView::draw(sf::RenderWindow& win)
{
	GameState state = displayableBoard.getGameState();

	sf::Text text;
	sf::Font font;
	font.loadFromFile("fonts/PressStart2P-Regular.ttf"); // semibold
	sf::RectangleShape field(sf::Vector2f(35, 35));

	int screen_height = win.getSize().x;
	int screen_width = win.getSize().y;
	int space = 40;

	for (int row = 0; row < height; ++row)
	{
		for (int col = 0; col < width; ++col)
		{
			char info = displayableBoard.getFieldInfo(row, col);
			float posX = (screen_height / height) + col * space;
			float posY = (screen_width / (width - 5)) + row * space;

			if (info == 'F')
				field.setFillColor(sf::Color(227, 177, 31));

			else if (info == 'x')
				field.setFillColor(sf::Color::Red);

			else if (info == '_')
				field.setFillColor(sf::Color::White);

			else if (info == '0')
				field.setFillColor(sf::Color(115, 199, 255));

			else
			{
				// add coloring to text that depends on mine count from blue -> red
				text.setString(info);
				text.setFont(font);
				text.setCharacterSize(20);
				text.setPosition(posX + 8, posY + 8);
				text.setFillColor(sf::Color::Black);
			}
			field.setPosition(posX, posY);

			sf::RectangleShape shadow;
			shadow.setSize(sf::Vector2f(field.getSize().x, field.getSize().y));
			shadow.setFillColor(sf::Color(0, 0, 0, 128));
			shadow.setPosition(field.getPosition().x + 5, field.getPosition().y + 5);

			win.draw(field);
			win.draw(shadow);
			win.draw(text);
		}
	}
	if (state != RUNNING)
		state == FINISHED_WIN ? std::cout << "\nYOU WIN\n" : std::cout << "\nYOU LOSE\n";
}

