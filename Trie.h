#include <unordered_set>
#include <string>
#include "TrieNode.h"

#ifndef __TRIE_H__
#define __TRIE_H__

class Trie
{
public:
	Trie(const char *, size_t);
	~Trie();

	void buildSubTrie(
		TrieNode* root,
		const char* chars, 
		size_t nchars, 
		std::unordered_set<size_t> skipinds);

	bool find(std::string);

	size_t size(void) {return _size;}
private:
	bool find(TrieNode*, std::string);
	
	TrieNode* root;
	size_t _size;
};

#endif
