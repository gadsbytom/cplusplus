#include "Scarab.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    Scarab scarab;
    const int windowSize = 400; 
    const int cellSize = windowSize / Scarab::size; 

    // RGB for Light Sky Blue
    sf::Color lightSkyBlue(135, 206, 250);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Scarab Matrix");

    // Pull the scarab image from disk
    sf::Texture beetle;

    if (!beetle.loadFromFile("beetle.jpg")) {
        std::cerr << "Failed to load texture from file" << std::endl;
    }

    // Define the sprite_b from the image
    sf::Sprite sprite_b;
    sprite_b.setTexture(beetle);

    // Define the sizing of the beetle
    sprite_b.setScale(
    float(cellSize) / sprite_b.getLocalBounds().width, 
    float(cellSize) / sprite_b.getLocalBounds().height
    );

    // Pull the scarab image from disk
    sf::Texture desert;

    if (!desert.loadFromFile("desert.jpg")) {
        std::cerr << "Failed to load texture from file" << std::endl;
    }

    // Define the sprite_b from the image
    sf::Sprite sprite_d;
    sprite_d.setTexture(desert);

    // Define the sizing of the beetle
    sprite_d.setScale(
    float(cellSize) / sprite_d.getLocalBounds().width, 
    float(cellSize) / sprite_d.getLocalBounds().height
    );


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
        // Draw the matrix
for (int i = 0; i < Scarab::size; ++i) {
    for (int j = 0; j < Scarab::size; ++j) {
        sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
        cell.setPosition(j * cellSize, i * cellSize);
        cell.setOutlineColor(sf::Color::Black);
        cell.setOutlineThickness(1);

        // Check if the current cell is part of the path
        if (scarab.isPath(i, j)) {
            sprite_d.setPosition(j * cellSize, i * cellSize);
            window.draw(sprite_d);
        } else {
            cell.setFillColor(lightSkyBlue);
            window.draw(cell);
        }


        if (scarab.isBlackBox(i, j)) {
            sprite_b.setPosition(j * cellSize, i * cellSize);
            window.draw(sprite_b);

            sf::RectangleShape border(sf::Vector2f(cellSize, cellSize));
            border.setPosition(j * cellSize, i * cellSize);
            border.setOutlineColor(sf::Color::Black);
            border.setOutlineThickness(1);
            border.setFillColor(sf::Color::Transparent); // Make the inside of the rectangle transparent
            window.draw(border);
        }
    }
}
        // Update the window
        window.display();
    }

    return 0;
}
