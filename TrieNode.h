#include <iostream>
#include <map>

#ifndef __TRIENODE_H__
#define __TRIENODE_H__


/*
	char Trie node class
	Children are hashed with map<> by character
*/
class TrieNode
{
public:
	// Various public constructors:
	TrieNode() : 
		parent(NULL), 
		children(std::map<char,TrieNode*>()), 
		val(0), 
		nchilds(0) 
		{}
	TrieNode(char val) : 
		parent(NULL), 
		children(std::map<char,TrieNode*>()), 
		val(val), 
		nchilds(0) 
		{}
	TrieNode(TrieNode* par, char val) :
		parent(par), 
		children(std::map<char,TrieNode*>()), 
		val(val), 
		nchilds(0) {}

	~TrieNode();

	/* 
		Add a child to it's children list
	*/
	void addChild(TrieNode*);

	/*
		Print the node data to stdcout
	*/
	void printNode(void);
private:

	// Data members
	TrieNode* parent;
	std::map<char,TrieNode*> children;
	size_t nchilds;
	char val;

	// Allow access to val property from Trie class
	friend class Trie;
};

#endif
