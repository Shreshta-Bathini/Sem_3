#include <iostream>
#include <string>
#include "trie.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
	int choice;  // 0 = implementation check, 1 = autocomplete
    	std::cin >> choice;

    	int n;
    	std::cin >> n;

    	Trie tr;
    	TrieNode* root = tr.getNode();

    	// Insert n words
    	for (int i = 0; i < n; i++) 
    	{
    	    	std::string word;
        	std::cin >> word;
        	tr.insert(root, word);
    	}

    	int m;
    	std::cin >> m;
    	std::cin.ignore(); // clear leftover newline before using getline

    	if (choice == 0) 
    	{
        	// Implementation check: search words
        	for (int i = 0; i < m; i++) 
        	{
            		std::string word;
            		std::cin >> word;
            		bool found = tr.search(root, word);
            		std::cout << word << "-"<< (found ? "Yes" : "No")<< std::endl;
        	}
    	} 
    	else 
    	{
        	// Autocomplete check: print suggestions
        	for (int i = 0; i < m; i++) 
        	{
            		std::string prefix;
            		std::getline(std::cin, prefix);  // can be empty string!
            		
            		int result = tr.printAutoSuggestions(root, prefix);
            		
            		if(result == 0) 
            		{
                		std::cout << "No word found with this prefix" << std::endl;
            		}
        	}
    	}

    	return 0;
}

