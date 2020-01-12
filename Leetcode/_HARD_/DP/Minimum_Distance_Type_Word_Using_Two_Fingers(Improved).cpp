class Solution {
public:
    vector<vector<vector<int>>>dp;
    int minimumDistance(string word) {
        dp.resize(word.size());
        for(auto &x:dp) x.resize(27,vector<int>(27, -1));
        return f(0,26,26,word);
    }
    
    int cost(int from,int to){
        if(from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    
    int f(int i,int first,int second,string& word){
        if(i >= word.size()) return 0;
        if(dp[i][first][second] != -1) return dp[i][first][second];
        int val = (int) word[i] - 'A';
        return dp[i][first][second] = min(cost(first,val) + f(i + 1,val,second,word),cost(second,val) + f(i + 1,first,val,word));
    }
};
