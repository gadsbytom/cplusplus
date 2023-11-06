#!/bin/bash

# SFML paths already set in .zshrc
source ~/.zshrc

# Compile the program
g++ -c Scarab.cpp -o Scarab.o -I"$SFML_INCLUDE_PATH"
g++ -c main.cpp -o main.o -I"$SFML_INCLUDE_PATH"
g++ Scarab.o main.o -o scarab_program -L"$SFML_LIBRARY_PATH" -lsfml-graphics -lsfml-window -lsfml-system

# Check if the program compiled successfully
if [ $? -eq 0 ]; then
    # Run the program if compilation was successful
    ./scarab_program
else
    echo "Compilation failed."
fi
