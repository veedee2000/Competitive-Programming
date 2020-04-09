class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0;i < v.size();i++){
            int val = 0,in = 0;
            for(int j = i;j < v.size();j++){
                val += v[j] * (++in);
            }
            ans = max(ans,val);
        }
        return ans;
    }
};
