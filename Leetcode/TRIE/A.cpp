struct Trie{
    struct Trie *child[2];
    bool end_of_word;
};

struct Trie* getnode(void){
    struct Trie* node = new Trie;
    node -> end_of_word = false;
    for(int i=0;i<2;i++){
        node -> child[i] = NULL;
    }
    return node;
} 

void insert(struct Trie* root, string word){

    for(int i = 0;i < word.size();i++){

        int index = word[i] - '0';
        
        if(!root -> child[index]){
            root -> child[index] = getnode();
        }
        root = root -> child[index];
    }
    root -> end_of_word = true;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        struct Trie* root = getnode();
        struct Trie* root1 = root;
        struct Trie* root2 = root;
        for(auto x:nums) insert(root, to_binary(x));
        string val = "";
        for(int i=0;i<32;i++){
            int c;
            if(root1 -> child[0] and root2 -> child[1]) {val += "1"; c = 0;}
            else if(root2 -> child[0] and root1 -> child[1]) {val += "1"; c = 1;}
            else if(root1 -> child[1] and root2 -> child[1]){val += "0"; c = -2;}
            else {val+="0"; c = -1;}
            if(c == 0){
                root1 = root1 -> child[0];
                root2 = root2 -> child[1];
            }
            else if(c == 1){
                root2 = root2 -> child[0];
                root1 = root1 -> child[1];
            }
            else if(c == -1){
                root1 = root1 -> child[0];
                root2 = root2 -> child[0];
            }
            else{
                root1 = root1 -> child[1];
                root2 = root2 -> child[1];
            }
        }
        // cout<<val;
        return stoi(val,0,2);
    }
    
    string to_binary(int x){
        string ans = "";
        for(int i = 31;i >=0;i--){
            if(x & (1<<i))  ans+="1";
            else ans+="0";
        }
        return ans;
    }
    
};
