#ifndef SCARAB_H
#define SCARAB_H

class Scarab {

public:
    Scarab(); // Constructor to initialize the matrix and place the black box
    bool isBlackBox(int i, int j) const; // Assuming this method is meant to be public
    void displayMatrix(); // Display the matrix on the screen
    void goLeft(); // Move the black box left
    void goRight(); // Move the black box right
    void goUp(); // Move the black box up
    void goDown(); // Move the black box down
    int x, y; // Position of the black box
    static const int size = 10; // Size of the matrix
    char matrix[size][size]; // The matrix
};

#endif // SCARAB_H
