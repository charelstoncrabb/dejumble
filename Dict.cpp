#include "Dict.h"

std::pair<std::string,int> split(std::string str)
{
	std::pair<std::string,int> ans;
	size_t i = 0;
	for(; str[i] != ' ' && i < str.size(); i++);
	ans.first = std::string(str.begin(),str.begin()+i);
	
	std::string second = std::string(str.begin()+i,str.end());
	ans.second = atoi(&second[0]);
	return ans;
}


void print(std::pair<std::string,int> sip)
{
	std::cout << "(" << sip.first << ", " << sip.second << ")" << std::endl;
}


Dict::Dict(const char* fname, size_t wllb, size_t wlub) :
	wllb(wllb), wlub(wlub)
{
	int i;
	std::ifstream fs(fname);
	char str[STR_LEN];
	while (fs.getline(str,STR_LEN))
	{
		std::string s(str);
		std::pair<std::string,int> dictentry = split(s);
		fulldict.push_back(dictentry);
	}
}


void Dict::dejumble(Trie trie)
{
	int inc;
	for(auto itr = fulldict.begin(); itr != fulldict.end(); ++itr)
	{
		if ((*itr).first.size() >= wllb && (*itr).first.size() <= wlub)
		{
			if (trie.find((*itr).first) && (*itr).second >= 0)
			{
				std::cout << (*itr).first << " ";
				std::cin >> inc;
				(*itr).second = (inc > 0 ? (*itr).second+1 : -1);
				print(*itr);
			}
		}
	}
}

void Dict::trainDejumble(Trie trie)
{
	for(auto s : dejumbled)
	{
		std::cout << s.first << " ";
	}
}


void Dict::writeTrained(const char* fname)
{
	std::ofstream fs(fname);
	for(auto itr : fulldict)
		fs << itr.first << " " << itr.second << std::endl;
}


void Dict::printDejumble(void)
{
	std::cout << "--------------\n  Dejumbled:\n--------------\n";
	for (auto s : dejumbled)
		std::cout << s.first << std::endl;
}

void Dict::printDict(void)
{
	for (auto s : fulldict)
		std::cout << s.first << std::endl;
}

