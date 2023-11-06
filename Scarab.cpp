#include "Scarab.h"
#include <iostream>
#include <random>



Scarab::Scarab() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, size - 1);
    
    // Generate random positions for x and y within the matrix bounds
    x = distrib(gen);
    y = distrib(gen);

    initializeMatrix();
    generatePath();
}


// Scarab::Scarab() : x(size / 2), y(size / 2) {
//     // Initialize the matrix with white spaces and place the black box in the center
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             matrix[i][j] = (i == y && j == x) ? 'X' : '.';
//         }
//     }
// }

bool Scarab::isBlackBox(int i, int j) const {
    // Implementation of isBlackBox. For example:
    return matrix[i][j] == 'X'; // Assuming 'X' represents the black box
}


void Scarab::displayMatrix() {
    // Display the matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Scarab::goLeft() {
    if (x > 0 && isPath(y, x - 1)) { // Check if the left cell is part of the path
        matrix[y][x] = '.';
        matrix[y][--x] = 'X';
    }
}

void Scarab::goRight() {
    if (x < size - 1 && isPath(y, x + 1)) { // Check if the right cell is part of the path
        matrix[y][x] = '.';
        matrix[y][++x] = 'X';
    }
}

void Scarab::goUp() {
    if (y > 0 && isPath(y - 1, x)) { // Check if the upper cell is part of the path
        matrix[y][x] = '.';
        matrix[--y][x] = 'X';
    }
}

void Scarab::goDown() {
    if (y < size - 1 && isPath(y + 1, x)) { // Check if the lower cell is part of the path
        matrix[y][x] = '.';
        matrix[++y][x] = 'X';
    }
}


// void Scarab::goLeft() {
//     if (x > 0) {
//         matrix[y][x] = '.';
//         matrix[y][--x] = 'X';
//     }
// }

// void Scarab::goRight() {
//     if (x < size - 1) {
//         matrix[y][x] = '.';
//         matrix[y][++x] = 'X';
//     }
// }

// void Scarab::goUp() {
//     if (y > 0) {
//         matrix[y][x] = '.';
//         matrix[--y][x] = 'X';
//     }
// }

// void Scarab::goDown() {
//     if (y < size - 1) {
//         matrix[y][x] = '.';
//         matrix[++y][x] = 'X';
//     }
// }

void Scarab::generatePath() {
    path.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, size - 1);

    // Start at the beetle's position
    int currentX = x;
    int currentY = y;
    path.push_back(std::make_pair(currentY, currentX));

    // Generate a random path of a certain length
    int pathLength = size; // For example, path length can be equal to the size of the matrix
    for (int i = 0; i < pathLength; ++i) {
        // Randomly choose to go up, down, left, or right
        std::uniform_int_distribution<> moveDistrib(0, 3);
        int move = moveDistrib(gen);

        // Apply the movement
        switch (move) {
            case 0: // Up
                if (currentY > 0) currentY--;
                break;
            case 1: // Down
                if (currentY < size - 1) currentY++;
                break;
            case 2: // Left
                if (currentX > 0) currentX--;
                break;
            case 3: // Right
                if (currentX < size - 1) currentX++;
                break;
        }
        // Add the new position to the path if it's not already there
        std::pair<int, int> newPos(currentY, currentX);
        if (std::find(path.begin(), path.end(), newPos) == path.end()) {
            path.push_back(newPos);
        }
    }
}


bool Scarab::isPath(int i, int j) const {
    return std::find(path.begin(), path.end(), std::make_pair(i, j)) != path.end();
}

// Private member function to initialize the matrix
void Scarab::initializeMatrix() {
    // Initialize the matrix with white spaces
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = '.';
        }
    }

    // Place the beetle at a random position
    x = rand() % size;
    y = rand() % size;
    matrix[y][x] = 'X'; // Assuming 'X' represents the beetle

    // If you need to initialize a path for the beetle, do it here
    // For example, a simple straight line to the right
    for (int i = x; i < size; ++i) {
        path.push_back(std::make_pair(y, i)); // This should work in any C++ version

    }
}

