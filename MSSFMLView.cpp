#include "MSSFMLView.h"

sf::RectangleShape MSSFMLView::addShadow(sf::RectangleShape field)
{
	sf::RectangleShape shadow;
	int xDir = 5;
	int yDir = 5;
	int alpha = 128;

	shadow.setSize(sf::Vector2f(field.getSize().x, field.getSize().y));
	shadow.setFillColor(sf::Color(0, 0, 0, alpha));
	shadow.setPosition(field.getPosition().x + xDir, field.getPosition().y + yDir);
	return shadow;
}

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
	font.loadFromFile("fonts/PressStart2P-Regular.ttf");
	sf::RectangleShape field(sf::Vector2f(35, 35));

	screen_height = win.getSize().x;
	screen_width = win.getSize().y;
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
				text.setString(info);
				text.setFont(font);
				text.setCharacterSize(20);
				text.setPosition(posX + 9, posY + 9);
				text.setFillColor(sf::Color::Black);
				field.setFillColor(sf::Color::White);
			}

			sf::Event event;
			if (event.MouseButtonPressed)

			field.setPosition(posX, posY);

			win.draw(field);
			win.draw(addShadow(field));
			win.draw(text);
		}
	}

	// -----------------------------------------------------------------------------

	int boxWidth = 200;
	int boxHeight = 75;

	int boxPosX = (screen_height / height) + (height * space) + 2 * space;
	int boxPosY = screen_width / (width - 5);

	float textPosX = boxPosX + boxWidth / 8;
	float textPosY = boxPosY + boxHeight / 3;

	sf::RectangleShape newGame;
	newGame.setSize(sf::Vector2f(boxWidth, boxHeight));
	newGame.setPosition(boxPosX, boxPosY);
	newGame.setFillColor(sf::Color::White);

	sf::Text newGameText("New Game", font, 20);
	newGameText.setPosition(textPosX, textPosY);
	newGameText.setFillColor(sf::Color::Black);

	win.draw(newGame);
	win.draw(addShadow(newGame));
	win.draw(newGameText);

	// -----------------------------------------------------------------------------

	sf::RectangleShape diff;
	diff.setSize(sf::Vector2f(boxWidth, boxHeight / 2));

	for (int i = 0; i < 3; ++i)
	{
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::Black);

		diff.setPosition(boxPosX, boxPosY + space * (3 + i + i));

		textPosY = diff.getPosition().y + (boxHeight / 2) / 3;

		switch (i)
		{
		case 0:
			text.setString("Easy");
			text.setPosition(textPosX, textPosY);
			break;
		case 1:
			text.setString("Normal");
			text.setPosition(textPosX, textPosY);
			break;
		case 2:
			text.setString("Hard");
			text.setPosition(textPosX, textPosY);
			break;
		}

		win.draw(diff);
		win.draw(addShadow(diff));
		win.draw(text);
	}

	// -----------------------------------------------------------------------------

	sf::RectangleShape author;
	author.setSize(sf::Vector2f(boxWidth, boxHeight / 2));
	author.setPosition(boxPosX, boxPosY + space * 9);

	sf::Text authorText("Created By: Dawid Schwinge", font, 6);
	authorText.setFillColor(sf::Color::Black);
	authorText.setPosition(textPosX, textPosY + space * 2 + 10);

	win.draw(author);
	win.draw(addShadow(author));
	win.draw(authorText);

	if (state != RUNNING)
		state == FINISHED_WIN ? std::cout << "\nYOU WIN\n" : std::cout << "\nYOU LOSE\n";
}

