bool comp(val a,val b){
    if(a.first != b.first) a.first < b.first;
    return a.second < b.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n){
    vector<int>dp(n,1);
    sort(p,p + n,comp);
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(p[i].first > p[j].second) dp[i] = max(dp[i],1 + dp[j]);
        }
    }
    int ans = 1;
    for(auto x:dp) ans = max(ans,x);
    return ans;
}
