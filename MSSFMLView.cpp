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

void MSSFMLView::drawNumber(sf::RenderWindow& win, char number, int x, int y)
{
	sf::Text text;
	sf::Font font;
	font.loadFromFile("fonts/PressStart2P-Regular.ttf");

	text.setString(number);
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(x + 9, y + 9);
	text.setFillColor(sf::Color::Black);

	win.draw(text);
}


void MSSFMLView::displayInfo(GameState state, sf::Font font, sf::RenderWindow& win)
{
	sf::Text text;
	
	switch (state)
	{
	case FINISHED_WIN:
		text.setFillColor(sf::Color(32, 122, 56));
		text.setString("You Won!");
		break;
	case FINISHED_LOSS:
		text.setFillColor(sf::Color(122, 32, 32));
		text.setString("You Lost!");
		break;
	case RUNNING:
		text.setFillColor(sf::Color(0, 0, 0, 192));
		text.setString("MINESWEEPER");
		break;
	}

	text.setFont(font);
	text.setCharacterSize(36);
	text.setPosition(80, 60);
	win.draw(text);
}

MSSFMLView::MSSFMLView(MinesweeperBoard& board) : displayableBoard(board)
{
	firstAction = true;
	revealAm = width * height;
	height = board.getBoardHeight();
	width = board.getBoardWidth();
}

void MSSFMLView::draw(sf::RenderWindow& win)
{
	state = displayableBoard.getGameState();
	screen_height = win.getSize().x;
	screen_width = win.getSize().y;
	int space = 40;

	sf::Text text;
	sf::Font font;
	font.loadFromFile("fonts/PressStart2P-Regular.ttf");
	sf::RectangleShape field(sf::Vector2f(35, 35));

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
			{
				field.setFillColor(sf::Color(115, 199, 255));
			}
			else
				field.setFillColor(sf::Color::White);

			field.setPosition(posX, posY);

			//revealAmount();
			//floodFill(row, col);

			win.draw(field);
			win.draw(addShadow(field));

			if (isdigit(info) && info != '0')
			{
				drawNumber(win, info, posX, posY);
			}
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

	displayInfo(state, font, win);
}

void MSSFMLView::revealAmount()
{
	if (firstAction && (mode == EASY || mode == NORMAL))
		revealAm *= 0.4;
	else if (firstAction && mode == HARD)
		revealAm *= 0.2;
	else if (revealAm < 1)
		revealAm = 1;
	else
		revealAm /= 2;
}

/*
void MSSFMLView::revealAround(int row, int col, int x, int y, sf::RenderWindow& win)
{
	if (isValidField(row, col)) return;

	for (int aRow = -1; aRow <= 1; ++aRow)
	{
		for (int aCol = -1; aCol <= 1; ++aCol)
		{
			int currRow = row + aRow;
			int currCol = col + aCol;
			char info = displayableBoard.getFieldInfo(currRow, currCol);

			if (isValidField(currRow, currCol) &&
				isdigit(displayableBoard.getFieldInfo(currRow, currCol)) &&
				info != '0')
			{
				drawNumber(win, info, x, y);
			}
		}
	}
}
*/

// brak mozliwosci odkrycia pola z mina
// algorytm niepoprawnie obniza wartosc licznika przez co odkrywa sie cala plansza
void MSSFMLView::floodFill(int row, int col, int counter)
{

	if (displayableBoard.getFieldInfo(row, col) == '#')
		return;

	if (!displayableBoard.isRevealed(row, col) &&
		!displayableBoard.hasFlag(row, col) &&
		!displayableBoard.hasMine(row, col) &&
		revealAm > 1)
	{
		displayableBoard.revealField(row, col);
		floodFill(row - 1, col, revealAm--);
		floodFill(row + 1, col, revealAm--);
		floodFill(row, col + 1, revealAm--);
		floodFill(row, col - 1, revealAm--);
	}
	else if (revealAm == 1)
		displayableBoard.revealField(row, col);
	else
		return;
}