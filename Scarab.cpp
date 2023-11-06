#include "Scarab.h"
#include <iostream>

Scarab::Scarab() : x(size / 2), y(size / 2) {
    // Initialize the matrix with white spaces and place the black box in the center
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = (i == y && j == x) ? 'X' : '.';
        }
    }
}

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
    if (x > 0) {
        matrix[y][x] = '.';
        matrix[y][--x] = 'X';
    }
}

void Scarab::goRight() {
    if (x < size - 1) {
        matrix[y][x] = '.';
        matrix[y][++x] = 'X';
    }
}

void Scarab::goUp() {
    if (y > 0) {
        matrix[y][x] = '.';
        matrix[--y][x] = 'X';
    }
}

void Scarab::goDown() {
    if (y < size - 1) {
        matrix[y][x] = '.';
        matrix[++y][x] = 'X';
    }
}
