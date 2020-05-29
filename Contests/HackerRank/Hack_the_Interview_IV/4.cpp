// https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/maximum-or-1/problem

const int mod = (int) 1e9 + 7;

int f(int i,int k,int greater,int smaller,vector<vector<vector<vector<int>>>>& dp,string& l,string& r){
    if(i == (int)l.size()) return (k == 0 and greater);
    if(k < 0) return 0;
    if(dp[i][k][greater][smaller] != -1) return dp[i][k][greater][smaller];
    int lo, hi;
    long long ans = 0;
    if(greater) lo = 0;
    else lo = l[i] - '0';
    
    if(smaller) hi = 9;
    else hi = r[i] - '0';
    
    ans = (ans + f(i + 1,k - (lo > 0),greater,smaller or (lo < hi),dp,l,r)) % mod; 
    
    if(hi - lo > 1) ans = (ans + ((long long) ((hi - lo - 1) * (long long) f(i + 1,k - 1,1,1,dp,l,r))) % mod) % mod;
    
    if(lo < hi) ans = (ans + f(i + 1,k - 1,1,smaller,dp,l,r)) % mod;
    
    return dp[i][k][greater][smaller] = ans;
}

int getNumberOfIntegers(string l, string r, int k) {
    int diff = (int)r.size() - (int)l.size();
    string zero;
    while(diff--) zero += "0";
    l = zero + l;
    vector<vector<vector<vector<int>>>>dp;
    dp.resize( (int) l.size(), vector<vector<vector<int>>>(k + 1, vector<vector<int>>(2, vector<int>(2, -1))));
    return f(0,k,0,0,dp,l,r);
}

