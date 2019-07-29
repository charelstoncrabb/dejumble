#include <string>
#include <ostream>
#include <istream>

#ifndef __LEXICON_H__
#define __LEXICON_H__

using namespace std;

class Lexicon
{
public:
	Lexicon(string data_filename); // Calls deserialize
	~Lexicon();					// Calls serialize

	bool update_prevalence(string,size_t);
	bool remove_word(string);

private:
	bool serialize(ostream&);
	bool deserialize(istream&);

	vector<Trie<pair<char,size_t>>> trie_list;
};

#endif
