#Makefile
all: add_nbo

add_nbo: main.cpp
	g++ -o add_nbo main.cpp

clean:
	rm -f add_nbo
