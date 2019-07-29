

dejumble: dejumble.o
	g++ -std=c++11 -g -o dejumble dejumble.o

dejumble.o:
	g++ -std=c++11 -g -c main.cpp -o dejumble.o

clean:
	$(RM) *.o
	$(RM) dejumble
