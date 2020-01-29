class Solution {
public:
    
    vector<string>ans;
    vector<vector<bool>>b;
    vector<int>dr,dc;
    unordered_map<string,bool>mp;
    
    struct trie{
        struct trie* child[26];
        bool endOfWord;
    };
    
    struct trie* getNode(){
        struct trie* root = new trie();
        for(int i = 0;i < 26;i++) root -> child[i] = NULL;
        root -> endOfWord = 0;
        return root;
    }
    
    void insert(struct trie* root,string word){
        for(auto x:word){
            if(!root -> child[x - 'a']) root -> child[x - 'a'] = getNode();
            root = root -> child[x - 'a'];
        }
        root -> endOfWord = 1;
    }
    
    void backtrack(int i,int j,string path,struct trie* root,vector<vector<char>>& board){
        if(b[i][j]) return;
        if(!root) return;
        if(root -> endOfWord){
            if(!mp.count(path)) ans.push_back(path);
            mp[path] = 1;
        }
        b[i][j] = 1;
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc],y = j + dc[rc];
            if(x >= 0 and y >= 0 and x < board.size() and y < board[0].size()){
                path.push_back(board[x][y]);
                backtrack(x,y,path,root -> child[board[x][y] - 'a'],board);
                path.pop_back();
            }
        }
        b[i][j] = 0;
    }

    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct trie* root = getNode();
        for(auto word : words) insert(root,word);
        dr = {-1,1,0,0}, dc = {0,0,-1,1};
        b.resize(board.size(),vector<bool>(board[0].size(),0));
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                string path = string(1,board[i][j]);
                backtrack(i,j,path,root -> child[board[i][j] - 'a'],board);
            }
        }
        return ans;
    }
};
