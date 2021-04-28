#include <iostream>

#include <SFML/Graphics.hpp>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "Actions.h"

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
    Actions actions(board, view);

    board.debugDisplay();

    // rozgrywka
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                switch (event.key.code)
                {
                case sf::Mouse::Left:
                    actions.lmbPressed(event);

                    actions.addEvents(event);

                    break;
                case sf::Mouse::Right:
                    actions.rmbPressed(event);
                    break;
                }
                break;
            }
        }

        // obsluga zdarzen
        window.clear(sf::Color(50, 55, 60));
        view.draw(window);   // wywolujemy funkcje draw i dostarczamy jej okno na ktorym ma odbyc sie rysowanie
        window.display();
    }
}