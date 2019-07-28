#include "TrieNode.h"

TrieNode::~TrieNode()
{
}


void TrieNode::addChild(TrieNode* child)
{
	child->parent = this;
	children[child->val] = child;
}

void TrieNode::printNode(void)
{
	std::cout << "--------" << std::endl;
	std::cout << "char: " << this->val << std::endl;
	std::cout << "parent: " << this->parent 
		<< " -> " << (this->parent ? this->parent->val : '\0') << std::endl;
	std::cout << "children: ";
	for(auto child : children)
		std::cout << child.second->val << ", ";
	std::cout << std::endl;
}

