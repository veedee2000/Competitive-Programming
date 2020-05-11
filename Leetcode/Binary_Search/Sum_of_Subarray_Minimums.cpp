class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& A) {
        vector<pair<int,int>>pairs;
        for(int i = 0;i < A.size();i++) pairs.push_back({A[i],i});
        sort(pairs.begin(),pairs.end());
        set<int>setA;
        int upperLimit,lowerLimit;
        int ans = 0;
        for(int i = 0;i < A.size();i++){
            
            auto limit = lower_bound(setA.begin(),setA.end(),pairs[i].second);
            
            if(limit == setA.end()) upperLimit = A.size();
            else upperLimit = *limit;
            
            if(limit == setA.begin()) lowerLimit = -1;
            else{
                advance(limit,-1);
                lowerLimit = *limit;
            }
            
            setA.insert(pairs[i].second);
            
            int leftSide = (pairs[i].second - lowerLimit - 1);
            int rightSide = (upperLimit - pairs[i].second - 1);
            
            ans = (ans + ((leftSide + rightSide + 1 + leftSide * rightSide) * pairs[i].first) % mod) % mod;
        }
        return ans;
    }
};
