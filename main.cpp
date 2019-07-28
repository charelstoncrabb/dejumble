#include "Trie.h"
#include "Dict.h"
#include <iostream>
#include <string>
#include <stdio.h>

bool isnum(char c)
{
	return ( (c >= 48) && (c <= 57) ? true : false );
}

int main(int argc, const char ** argv)
{
	char * chars;
	size_t wllb = 3, nchars = argc-1;
	chars = (char*)malloc(sizeof(char)*nchars);
	for(int i = 1; i < argc; i++) 
	{
		if (isnum(*argv[i]))
		{
			wllb = *argv[i] - 48;
			continue;
		}
		chars[i-1] = *argv[i];
	}

	// Build Trie from arg chars
	Trie trie(chars,nchars);

	// Parse english words for appropriate-length words:
	Dict dict("english-words/words_alpha_train.txt",wllb,nchars);

	// Display and label cross-referenced dejumbled words:
	dict.dejumble(trie);

	// Write to training file for later accumulation
	dict.writeTrained("english-words/words_alpha_train.txt");

	//----------
	free(chars);
    return 0;
}
