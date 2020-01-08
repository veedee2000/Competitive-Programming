class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int>ans;
        ans.push_back(start);
        for(int i = 0;i < n;i++){
            int sz = ans.size();
            for(int j = sz - 1;j >= 0;j--){
                ans.push_back(ans[j] ^ (1 << i));
            }
        }
        return ans;
    }
};
