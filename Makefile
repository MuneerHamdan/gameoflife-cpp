all:
	g++ ncurses.cpp -lncurses
	./a.out
	rm a.out
