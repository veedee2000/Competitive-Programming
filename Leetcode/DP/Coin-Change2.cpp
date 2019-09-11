//TOP DOWN: 

class Solution {
private:
    int dp[10010][310],i,b[11000][310],j;
public:
    Solution(){
        for(i=0;i<10000;i++) for(j=0;j<300;j++) dp[i][j] = 0;
        for(i=0;i<10000;i++) for(j=0;j<300;j++) b[i][j] = 0;
    }
    int change(int amount, vector<int>& coins) {
        return ans(coins,amount,0);
    }
    int ans(vector<int>& coins, int amount, int state){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(b[amount][state] == 1) return dp[amount][state];
        for(int x=state;x < coins.size();x++){
            dp[amount][state] += ans(coins,amount - coins[x],x);
        }
        b[amount][state]=1;
        return dp[amount][state];
    }
};


//Alternate Beautiful Solution (BOTTOM UP APPROACH):

class Solution {
private:
    int dp[10010][310],i,b[11000][310],j;
public:
  int change(int t, vector<int>& cs) {
  int dp[t + 1] = { 1 };
  for (auto c : cs)
    for (auto j = c; j <= t; ++j) dp[j] += dp[j - c];
  return dp[t];
}
};
