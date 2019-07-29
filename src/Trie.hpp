

#ifndef __TRIE_TPP__
#define __TRIE_TPP__

// Forward declaration for TrieNode definition
template<class T>
class Trie;


// T must be hashable
template<class T>
class TrieNode
{
public:
	TrieNode(){}
	TrieNode(T init_datum) : datum(init_datum) {}

private:
	T datum;
	std::map<T,TrieNode<T>*> children;

	friend class Trie<T>;
};


/*
	Trie class data structure puts arrays of (hashable) data
	types T (e.g., char) into a trie tree structure
	T must be hashable
*/
template<class T>
class Trie
{
public:
	Trie()
	{
		root = new TrieNode<T>();
	}

	/*
		Search trie for provided data array
		Returns true if data array is in trie
	*/
	bool find(T* data, size_t data_len)
	{
		return _find(root,data,data_len);
	}

	/*
		Inserts new data array into trie
		Returns true if insert is successful
	*/
	bool insert(T* new_data, size_t data_len)
	{
		return _insert(root,new_data,data_len);
	}

	/*
		Erases provided data array from trie
		Returns true if erase is successful
	*/
	bool erase(T* data, size_t data_len)
	{
		size_t& data_len_copy = data_len;
		return _erase(root,data,data_len_copy);
	}

	/*
		Return size of trie
	*/
	size_t size(void){return _size;}

private:
	// Private helpers for recursion
	bool _find(TrieNode<T>* root, T* data, size_t data_len)
	{
		if (data_len == 0) return true;
		if (root->children.find(data[0]) == root->children.end()) return false;
		return _find(root->children[data[0]],data[1],data_len-1);
	}

	bool _insert(TrieNode<T>* root, T* data, size_t data_len)
	{
		if (data_len == 0) return true;
		if (root->children.find(data[0]) == root->children.end())
			root->children[data[0]] = new TrieNode<T>(data[0]);
		return _insert(root->children[data[0]],data[1],data_len-1);
	}

	bool _erase(TrieNode<T>* root, T* data, size_t& data_len)
	{
		bool ans = true;
		if (data_len == 0) return ans;
		if (root->children.find(data[0]) == root->children.end()) return false;
		if (data_len > 1)
			ans = _erase(root->children[data[0]],data[1],data_len-1);
		if (data_len == 1)
		{
			delete root->children[data[0]];
			root->children.erase(data[0]);
			if (root->children.empty()) data_len--;
		}
		return ans;
	}

	// Data members:
	TrieNode<T>* root;
	size_t _size;
};

#endif
