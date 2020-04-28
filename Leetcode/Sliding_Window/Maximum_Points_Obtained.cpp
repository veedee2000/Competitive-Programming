class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(),sum = 0,val = 0;
        for(auto x:cardPoints) sum += x;
        for(int i = 0;i < n - k;i++) val += cardPoints[i];
        int ans = sum - val;
        for(int i = 0;i < k;i++){
            val += cardPoints[i + n - k] - cardPoints[i];
            ans = max(ans,sum - val);
        }
        return ans;
    }
};
