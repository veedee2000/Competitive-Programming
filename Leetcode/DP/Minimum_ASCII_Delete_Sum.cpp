class Solution {
public:
    vector<vector<int>>dp;
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return f(s1.size(),s1,s2.size(),s2);
    }
    
    int f(int i,string& s1,int j,string& s2){    // Forgeting pass by referance of strings results in MLE so BEWARE!!!
        if(i < 0 or j < 0 or (i == 0 and j == 0)) return 0;
        if(j == 0){
            return dp[i][j] = f(i - 1,s1,j,s2) + (int) s1[i - 1];
        }
        if(i == 0){
            return dp[i][j] = f(i,s1,j - 1,s2) + (int) s2[j - 1];
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i - 1] == s2[j - 1]) dp[i][j] = f(i - 1,s1,j - 1,s2);
        else dp[i][j] = min(f(i - 1,s1,j,s2) + (int) s1[i - 1],f(i,s1,j - 1,s2) + (int) s2[j - 1]);
        return dp[i][j];
    }
};
