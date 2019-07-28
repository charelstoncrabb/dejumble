#include <unordered_set>
#include <string>
#include "TrieNode.h"

#ifndef __TRIE_H__
#define __TRIE_H__

/*
	character-based trie data structure
*/
class Trie
{
public:
	/*
		Public constructor
		array of characters, length of array
	*/
	Trie(const char *, size_t);
	~Trie();

	/*
		Constructor helper function to construct
		the trie recursively
	*/
	void buildSubTrie(
		TrieNode* root,
		const char* chars, 
		size_t nchars, 
		std::unordered_set<size_t> skipinds);

	/*
		Search the trie tree to see if the provided
		string exists in the trie
	*/
	bool find(std::string);

	/*
		Return current size of trie
	*/
	size_t size(void) {return _size;}
private:

	/*
		Helper find function to traverse trie recursively
	*/
	bool find(TrieNode*, std::string);
	
	// Data members
	TrieNode* root;
	size_t _size;
};

#endif
