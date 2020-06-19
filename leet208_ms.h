#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
using namespace std;

class Trie {
public:
	typedef struct _TrieNode
	{
		bool bEnd;
		_TrieNode* nextLevel[26];
		_TrieNode() {
			bEnd = false;
			memset(&nextLevel, 0, sizeof(int)*26);
		}
	}TrieNode;


	TrieNode* root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* cur = root;
		for (int i=0;i<word.size();++i)
		{
				cur->nextLevel[word[i]-'a'] = new TrieNode();
				cur = cur->nextLevel[word[i] - 'a'];
				if (i == word.size()-1){
					cur->bEnd = true;
				}
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* cur = root;
		for (int i=0;i<word.size();++i){
			if (cur->nextLevel[word[i]-'a'] != 0){
				cur = cur->nextLevel[word[i] - 'a'];
				if (i == word.size() - 1 && cur->bEnd == true) {
					return true;
				}
			}
		}

		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		if (prefix.size() == 0){
			return false;
		}
		TrieNode* cur = root; 
		for (int i = 0; i < prefix.size(); ++i) {
			if (cur->nextLevel[prefix[i] - 'a'] != 0) {
				cur = cur->nextLevel[prefix[i] - 'a'];
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

void test_leet208() {

	Trie* trie = new Trie();
	trie->insert("p");
	trie->startsWith("pr");
	trie->insert("apple");
	trie->search("apple");   // 返回 true
	trie->search("app");     // 返回 false
	trie->startsWith("app"); // 返回 true
	trie->insert("app");
	trie->search("app");     // 返回 true

	//printf("%d", validTree(5,v4));
}


