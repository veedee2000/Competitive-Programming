#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class TrieNode{
public:
    vector<TrieNode *> children;
    bool is_prefix;
    bool is_word;
    TrieNode(): is_prefix(true), is_word(false), children(vector<TrieNode *>(26, nullptr)){}
};

class Trie {
private:
    TrieNode * root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * node = root;
        
        for(char c : word){
            if(!node->children[c - 'a']){
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    
    /* 
        word.c_str() return the ptr to the string head, terminates the word with '\0'
    */
    bool search(string word) {
        return search(word.c_str(), root);
    }
    
    /* divide-and-conquer */
    bool search(const char * word, TrieNode * node){
       
        for(int i = 0; word[i] !='\0' && node != nullptr; i++){
            if(node->children[word[i] - 'a']){
                return search(word + i + 1, node->children[word[i] - 'a']);
            }
            else{
                return false;
            }
        }
        
        return node->is_word;
    }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for(int i = 0; prefix[i] !='\0' && node != nullptr; i++){
            if(node->children[prefix[i] - 'a']){
                node = node->children[prefix[i] - 'a'];
            }
            else{
                return false;
            }
        }
        return node->is_prefix;
    }
};
