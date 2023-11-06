#include "Scarab.h"
#include <SFML/Graphics.hpp>

int main() {
    Scarab scarab;
    const int windowSize = 400; // Size of the window
    const int cellSize = windowSize / Scarab::size; // Size of one cell in the window

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Scarab Matrix");

    // Main loop that continues until we close the window
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Left: scarab.goLeft(); break;
                    case sf::Keyboard::Right: scarab.goRight(); break;
                    case sf::Keyboard::Up: scarab.goUp(); break;
                    case sf::Keyboard::Down: scarab.goDown(); break;
                    default: break;
                }
            }
        }

        // Clear the window with white color
        window.clear(sf::Color::White);

        // Draw the matrix
        for (int i = 0; i < Scarab::size; ++i) {
            for (int j = 0; j < Scarab::size; ++j) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(1);

                if (scarab.isBlackBox(i, j)) {
                    cell.setFillColor(sf::Color::Black);
                } else {
                    cell.setFillColor(sf::Color::White);
                }

                window.draw(cell);
            }
        }

        // Update the window
        window.display();
    }

    return 0;
}
