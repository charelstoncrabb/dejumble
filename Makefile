

dejumble: dejumble.o TrieNode.o Trie.o Dict.o
	g++ -std=c++11 -g -o dejumble dejumble.o TrieNode.o Trie.o Dict.o

dejumble.o:
	g++ -std=c++11 -g -c main.cpp -o dejumble.o

TrieNode.o:
	g++ -std=c++11 -g -c TrieNode.cpp

Trie.o:
	g++ -std=c++11 -g -c Trie.cpp

Dict.o:
	g++ -std=c++11 -g -c -DSTR_LEN=100 Dict.cpp

clean:
	$(RM) *.o
	$(RM) dejumble
