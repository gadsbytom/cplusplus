# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Set the noninteractive environment variable ot prevent user input
ENV DEBIAN_FRONTEND noninteractive

# Set the working directory in the container
WORKDIR /usr/src/app

# Install any needed packages specified
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    libopencv-dev \
    tesseract-ocr libtesseract-dev

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Make port 80 available to the world outside this container
#EXPOSE 80

# Define environment variable
#ENV NAME World

# Build the C++ project
RUN cmake .
RUN make 
RUN chmod +x /usr/src/app/image_processing

# Run the output program when the container launches
CMD ["./image_processing"]
