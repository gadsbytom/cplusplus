#!/bin/bash

# Define your image name
IMAGE_NAME="image_1"

# Path to your host directory where your images are stored
HOST_IMAGE_PATH="path/to/code"

# Name of the directory in the container (should match the WORKDIR in Dockerfile)
DATA_DIR="/usr/src/app/data"

# Build the Docker image
docker build -t ${IMAGE_NAME} .

# Run the Docker container
docker run -v ${HOST_IMAGE_PATH}:${DATA_DIR} image_processing ${DATA_DIR}/your_image.jpg
