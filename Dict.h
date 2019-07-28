#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Trie.h"

#ifndef __DICT_H__
#define __DICT_H__


class Dict
{
public:
	Dict(const char*, size_t, size_t);

	void printDict(void);
	void dejumble(Trie);
	void trainDejumble(Trie);
	void writeTrained(const char*);
	void printDejumble(void);

private:
	std::vector<std::pair<std::string,int> > fulldict;
	std::vector<std::pair<std::string,int> > dejumbled;
	size_t wllb, wlub;
};

#endif
