#include "Trie.h"

Trie::Trie(const char * chars, size_t nchars)
{
	root = new TrieNode();
	std::unordered_set<size_t> skipinds;
	buildSubTrie(root,chars,nchars,skipinds);
}

Trie::~Trie()
{

}

void Trie::buildSubTrie(
	TrieNode* root,
	const char* chars, 
	size_t nchars, 
	std::unordered_set<size_t> skipinds)
{
	for(size_t i = 0; i < nchars; i++)
	{
		if (skipinds.find(i) != skipinds.end())
			continue;
		TrieNode* child = new TrieNode(chars[i]);
		root->addChild(child);
		//std::cout << "Adding child:" << std::endl;
		//child->printNode();
		_size++;
		skipinds.insert(i);
		buildSubTrie(child,chars,nchars,skipinds);
		skipinds.erase(i);
	}
}


bool Trie::find(std::string str)
{
	return this->find(root,str);
}

bool Trie::find(TrieNode* root, std::string str)
{
	//std::cout << "\nSearching for: " << str << std::endl;
	if (!str.size())
		return true;
	std::map<char,TrieNode*>::iterator itr
		= root->children.find(str[0]);
	if (itr != root->children.end())
	{
		//std::cout << "Found first char at node:" << std::endl;
		//itr->second->printNode();
		str.erase(str.begin());
		return this->find(itr->second,str);
	}
	return false;

}
