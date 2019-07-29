#include <map>
#include <string>
#include <string.h>
#include <iostream>

#include "src/Trie.hpp"
#include "extern/argparse/argparse.hpp"

using namespace std;

// Helper function to take CL args and dump into a pair
pair<string,size_t> parse_args(int argc, const char** argv)
{
	string chars = "";
	string min_len_str = "";
	size_t min_len;
	ArgumentParser parser;
	{
		parser.appName("dejumble");
		parser.addArgument("-m","--minlen",1,false);
		parser.addArgument("-c","--chars",1,false);
		parser.parse(argc,argv);
		min_len_str = parser.retrieve<string>("m");
		chars = parser.retrieve<string>("c");
		min_len = (size_t)atoi(min_len_str.data());
	}
	return pair<string,size_t>(chars,min_len);
}


int main(int argc, const char** argv)
{
	pair<string,size_t> jumbled_prob = parse_args(argc,argv);

	return 0;
}
