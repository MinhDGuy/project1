all:
	g++ -I src/include -L src/lib -g -o main src/main.cpp src/RenderWindow.cpp src/Entity.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
