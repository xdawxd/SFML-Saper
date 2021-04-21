#include <iostream>

#include <SFML/Graphics.hpp>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

void intro()
{
    std::cout << "Dawid (----39)" << "\n";
    std::cout << "Grupa: Sroda 13:15 (MW)" << "\n" << "\n";
}

int main()
{
    srand(time(nullptr));

    constexpr int screen_width = 800;
    constexpr int screen_height = 600;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Minesweeper");

    MinesweeperBoard board(10, 10, EASY);
    MSSFMLView view(board);  // przekazujemy przez referencje plansze jako argument konstruktora

    board.debugDisplay();

    // rozgrywka
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            int row = event.mouseButton.y / 40 - 3;
            int col = event.mouseButton.x / 40 - 2;

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:

                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    board.revealField(row, col);

                    if ((x >= 560 && x <= 760) && (y >= 120 && y <= 195))
                    {
                        board.setBoard();
                        board.debugDisplay();
                    }

                    else if ((x >= 560 && x <= 760) && (y >= 240 && y <= 275))
                    {
                        board.setDifficulty(EASY);
                        board.debugDisplay();
                    }

                    else if ((x >= 560 && x <= 760) && (y >= 320 && y <= 355))
                    {
                        board.setDifficulty(NORMAL);
                        board.debugDisplay();
                    }

                    else if ((x >= 560 && x <= 760) && (y >= 400 && y <= 435))
                    {
                        board.setDifficulty(HARD);
                        board.debugDisplay();
                    }
                    break;
                case sf::Mouse::Right:
                    board.toggleFlag(row, col);
                    break;
                }
                break;
            /*
            case sf::Event::MouseButtonReleased:

                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    std::cout << "Left Mouse released" << std::endl;
                    //view.clickAnimation2(row, col);
                    break;
                case sf::Mouse::Right:
                    std::cout << "Right Mouse released" << std::endl;
                    //view.clickAnimation2(row, col);
                    break;
                }
                break;
             */
            }
        }

        // obsluga zdarzen
        window.clear(sf::Color(50, 55, 60));
        view.draw(window);   // wywolujemy funkcje draw i dostarczamy jej okno na ktorym ma odbyc sie rysowanie
        window.display();
    }
}