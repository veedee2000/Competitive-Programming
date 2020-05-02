TLE - Assigning Hat to a Person

class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<long long,long long>dp;
    int numberWays(vector<vector<int>>& hats) {
        return f(0,0,hats);
    }
    
    int f(int i,long long hash,vector<vector<int>>& hats){
        if(i == hats.size()) return 1;
        if(dp.count(hash)) return dp[hash];
        long long ans = 0;
        for(auto x:hats[i]){
            if(hash & (1 << x)) continue;
            ans = (ans + f(i + 1,hash | (1 << x),hats)) % mod;
        }
        return dp[hash] = ans;
    }
};
AC - Assigning Person to a Hat

class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<int,unordered_map<int,int>>dp;
    unordered_map<int,unordered_set<int>>mp;
    int numberWays(vector<vector<int>>& hats) {
        for(int i = 0;i < hats.size();i++){
            for(auto x:hats[i]) mp[x].insert(i);
        }
        return f(0,40,hats.size() - 1);
    }
    
    int f(int hash,int maxHat,int count){
        if(count < 0) return 1;
        if(maxHat == 0) return 0;
        if(dp[hash].count(maxHat)) return dp[hash][maxHat];
        long long ans = f(hash,maxHat - 1,count);
        for(auto people:mp[maxHat]){
            if(hash & (1 << people)) continue;
            ans = (ans + f(hash | (1 << people),maxHat - 1,count - 1)) % mod;
        }
        return dp[hash][maxHat] = ans;
    }
};
Explanation : The initial and more intuitive idea was to assign people a hat to a person. 
So, basically we assign a hat and then check that with this hat already assigned,
how many different ways it is possible to assign the remaining hats to the persons.

The second and more complicated idea to arrive at revolves around the fact that 
the Time Complexity is high for the previous approach 
bcz of fact that each person can wear at most 40 different hats and hence the max number of operations is 2 ^ 40 * 10.
Instead of this, we try to assign persons to hats. 
Here, if there are two possible cases, either assign the current hat to some person who hasn't already been assigned ( (1 << people) & hash ) checks this part or dont assign the hat at all.
This solution is pretty complicated to arrive to so don't be demoralized if u couldn't find it (as neither did I, by myself :) )
