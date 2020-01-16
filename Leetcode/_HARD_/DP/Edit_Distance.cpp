class Solution {
public:
    vector<vector<int>>dp;
    string word1,word2;
    int minDistance(string word1, string word2) {
        if(word1.size() == 0 or word2.size() == 0) return max(word1.size(),word2.size());
        int sz = max(word1.size(),word2.size());
        this -> word1 = word1;
        this -> word2 = word2;
        dp.resize(sz,vector<int>(sz,-1));
        int ans = INT_MAX;
        for(int i = 0;i < word1.size();i++){
            ans = min(ans,i + f(i,0));
        }
        return ans;
    }
    
    int f(int i,int j){
        if(i == word1.size()) return (word2.size() - j);
        if(j == word2.size()) return (word1.size() - i);
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) dp[i][j] = f(i + 1,j + 1);
        else dp[i][j] = min({1 + f(i + 1,j),1 + f(i + 1,j + 1),1 + f(i,j + 1)});
        return dp[i][j];
    }
};
