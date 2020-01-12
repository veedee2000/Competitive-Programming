class Solution {
public:
    vector<vector<vector<int>>>dp;
    int minimumDistance(string word) {
        dp.resize(word.size());
        for(auto &x:dp) x.resize(27,vector<int>(27, -1));
        return f(0,26,26,word);
    }
    
    int f(int i,int first,int second,string& word){
        if(i >= word.size()) return 0;
        if(dp[i][first][second] != -1) return dp[i][first][second];
        int val = (int) word[i] - 'A';
        if(first == 26 and second == 26) dp[i][first][second] = min(f(i + 1,val,second,word),f(i + 1,first,val,word));
        
        else if(first == 26) dp[i][first][second] = min(f(i + 1,val,second,word),abs(second / 6 - val / 6) + abs(second % 6 - val % 6) + f(i + 1,first,val,word));
        
        else if(second == 26) dp[i][first][second] = min(abs(first / 6 - val / 6) + abs(first % 6 - val % 6) + f(i + 1,val,second,word),f(i + 1,first,val,word));
        
        else dp[i][first][second] = min(abs(first / 6 - val / 6) + abs(first % 6 - val % 6) + f(i + 1,val,second,word),abs(second / 6 - val / 6) + abs(second % 6 - val % 6) + f(i + 1,first,val,word));
        
        return dp[i][first][second];
    }
};
