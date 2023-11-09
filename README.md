# Project Repository

This repository contains two main components: the `scarab` game and the `NLP` pipeline. Below you will find instructions on how to set up and run each part.

## scarab Game

### Overview
The `scarab` folder contains a game where the player maneuvers a beetle through obstacles in a desert environment. It's a thrilling and engaging game that runs locally on your machine.

### Running the Game
To run the game, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the `scarab` folder in your terminal.
3. Run the game using the provided shell script:
    ```
    ./run_scarab.sh
    ```
Make sure you have the necessary permissions to execute the script. If not, run `chmod +x run_scarab.sh` to make it executable.

## NLP Pipeline

### Overview
The `NLP` folder contains a Docker-based pipeline that uses Optical Character Recognition (OCR) to extract text from images. The entire pipeline is containerized, making it portable and easy to build in any environment with Docker installed.

### Building the Docker Container
To build and run the NLP pipeline, you need to have Docker installed on your machine. After installing Docker, perform the following:

1. Clone the repository to your local machine.
2. Navigate to the `NLP` folder in your terminal.
3. Build the Docker container with the provided shell script:
    ```
    ./build_container.sh
    ```
As with the game script, ensure you have the right permissions to run the script by executing `chmod +x build_container.sh` if necessary.

### Pipeline Structure
The pipeline is defined by a `Dockerfile` and `CMakeLists.txt`, which ensure that all dependencies are correctly installed and that the pipeline is correctly set up during the Docker build process.

## General Prerequisites
- Git (for cloning the repository)
- Bash shell (for running `.sh` scripts)
- Docker (for building and running the NLP pipeline)
