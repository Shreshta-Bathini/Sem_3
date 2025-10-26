#include <string>

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode 
{
	struct TrieNode* children[ALPHABET_SIZE] = {NULL};

	// isWordEnd is true if the node represents
	// end of a word
	bool isWordEnd = false;
};

class Trie
{
	public:
	    	TrieNode* root;

	    	Trie();
	    	
	    	struct TrieNode* getNode(void);
	    	
	    	void insert(struct TrieNode* root, const std::string key);
	    	
	    	bool search(struct TrieNode *root, std::string key);
	    	
	    	bool isLastNode(struct TrieNode* root);
	    	
	    	void suggestionsRec(struct TrieNode* root, std::string currPrefix);
	    	
	    	int printAutoSuggestions(TrieNode* root, const std::string query);
};
