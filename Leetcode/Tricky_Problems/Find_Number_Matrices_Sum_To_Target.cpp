class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int>currArray(m,0);
        unordered_map<int,int>mp;

        for(int L = 0;L < n;L++){
            for(auto &x:currArray) x = 0;
            for(int R = L;R < n;R++){
                for(int i = 0;i < m;i++) currArray[i] += matrix[i][R];
                int prefix = 0;
                mp[0] = 1;
                for(int i = 0;i < m;i++){
                    prefix += currArray[i];
                    ans += mp[prefix - target];
                    mp[prefix]++;
                }
                mp.clear();
            }
        }

        return ans;
    }
};
