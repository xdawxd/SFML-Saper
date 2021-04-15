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
/*
int main()
{
    intro();
    srand(time(nullptr));

    MinesweeperBoard board(5, 5, NORMAL);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);

    ctrl.play();
}
*/

int main()
{
    constexpr int screen_width = 800;
    constexpr int screen_height = 600;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Minesweeper");

    MinesweeperBoard board(10, 10, DEBUG);
    MSSFMLView view(board);  // przekazujemy przez referencje plansze jako argument konstruktora

    // symulujemy rozgrywke
    board.toggleFlag(0, 0);
    board.revealField(2, 3);

    // rysujemy
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // obsluga zdarzen
        //
        window.clear();
        view.draw(window);   // wywolujemy funkcje draw i dostarczamy jej okno na ktorym ma odbyc sie rysowanie
        window.display();
    }
}