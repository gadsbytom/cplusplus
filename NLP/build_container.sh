#!/bin/bash

# Define your image name
IMAGE_NAME="image_1"

# Path to your host directory where your images are stored
HOST_IMAGE_PATH="/Users/tom/Code/c++/cplusplus/NLP"

# Name of the directory in the container (should match the WORKDIR in Dockerfile)
DATA_DIR="/usr/src/app/data"

# name of image
PROCESSOR_NAME="all_processing"

# Build the Docker image
docker build --build-arg PROCESSOR_NAME=${PROCESSOR_NAME} -t ${IMAGE_NAME} .

# Run the Docker container
docker run ${IMAGE_NAME} ./${PROCESSOR_NAME} ${DATA_DIR}/oj.jpg
