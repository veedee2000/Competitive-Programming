class Solution {
    int dp[100000];
public: 
    
    Solution(){
        memset(dp,0,sizeof(dp));
    }
    
    int numTrees(int n){
		if(n < 2) return 1;
		if(dp[n]) return dp[n];
		for(int i = 0;i < n;i++){
			dp[n] += numTrees(i) * numTrees(n - i - 1); 
		}
		return dp[n];
    }
};
