#include<bits/stdc++.h>

using namespace std;

struct Trie{
    struct Trie *child[26];
    bool end_of_word;
};

struct Trie* getnode(void){
    struct Trie* node = new Trie;
    node -> end_of_word = false;
    for(int i=0;i<26;i++){
        node -> child[i] = NULL;
    }
    return node;
} 

bool insert(struct Trie* root, string word){

    for(int i = 0;i < word.size();i++){

        int index = word[i] - 'a';
        
        if(!root -> child[index]){
            root -> child[index] = getnode();
        }
        root = root -> child[index];
    }
    root -> end_of_word = true;
}

int main(){
  
  struct Trie* root = getnode();
  
  // Do the needed stuff
  
  return 0;
}
