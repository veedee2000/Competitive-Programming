class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        for(auto x:coins){
            if(x <= ans + 1) ans += x;
        }
        return ans + 1;
    }
};
