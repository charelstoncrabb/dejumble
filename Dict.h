#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Trie.h"

#ifndef __DICT_H__
#define __DICT_H__

/*
	Basic dictionary class for parsing and accumulating the 
	word annotations

*/
class Dict
{
public:
	Dict(const char*, size_t, size_t);

	/*
		Print the full dictionary to stdcout
	*/
	void printDict(void);

	/*
		Perform the dejumble operation using the trie structure
		-- filters dictionary by words available in trie
	*/
	void dejumble(Trie);

	/*
		Prints available dejumbled words and prompts for 
		annotation
	*/
	void trainDejumble(Trie);

	/*
		Rewrites the updated annotations to data file
	*/
	void writeTrained(const char*);

	/*
		Print available dejumbled words without annotation prompt
	*/
	void printDejumble(void);

private:

	// Data members
	std::vector<std::pair<std::string,int> > fulldict;
	std::vector<std::pair<std::string,int> > dejumbled;
	size_t wllb, wlub; // Word length lower/upper bounds
};

#endif
