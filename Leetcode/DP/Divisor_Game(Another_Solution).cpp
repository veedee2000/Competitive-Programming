class Solution {
public:
    vector<bool>dp,visited;
    
    bool divisorGame(int N) {
        dp.resize(N + 1,0);
        visited.resize(N + 1,0);
        return f(N,1);
    }
    
    bool f(int n,bool c){
        if(n < 2) return !c;
        if(visited[n]) return dp[n];
        bool see = 0;
        visited[n] = 1;
        for(int i = 1;i < n;i++){
            if(n % i == 0) see |= f(n - i,!c);
        }
        return dp[n] = see;
    }
};
