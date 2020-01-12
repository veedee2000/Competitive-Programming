class Solution {
public:
    vector<vector<int>>dp;
    int minimumDistance(string word) {
        dp.resize(word.size(),vector<int>(27,-1));
        return f(1,26,word);
    }
    
    int cost(int from,int to){
        if(from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    
    int f(int i,int finger,string& word){
        if(i >= word.size()) return 0;
        if(dp[i][finger] != -1) return dp[i][finger];
        int val = (int) word[i] - 'A';
        int pre = (int) word[i - 1] - 'A';
        return dp[i][finger] = min(cost(finger,val) + f(i + 1,pre,word),cost(pre,val) + f(i + 1,finger,word));
    }
};
