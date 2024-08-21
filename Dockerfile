FROM ubuntu
COPY . /app
WORKDIR /app
RUN apt update && apt upgrade -y && \
    apt install build-essential -y && \
    g++ -Wall --verbose -static -Ofast -o dist/bfasm -Iinclude src/bfasm/*.cpp src/bfasm.cpp
CMD ./dist/bfasm
