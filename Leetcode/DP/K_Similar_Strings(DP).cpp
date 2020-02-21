class Solution {
public:
    unordered_map<string,int>dp;
    int kSimilarity(string A, string B) {
        return f(A,0,B);
    }
    
    int f(string curr,int id,string B){
        if(curr == B) return 0;
        if(dp.count(curr)) return dp[curr];
        while(id < B.size() and curr[id] == B[id]) id++;
        int ans = INT_MAX;
        for(int i = id + 1;i < B.size();i++){
            if(curr[i] == B[id]){
                string buff = curr;
                swap(buff[i],buff[id]);
                ans = min(ans,f(buff,id,B));
            }
        }
        return dp[curr] = 1 + ans;
    }
    
};
