class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
        int m = a[0].size(),n = a.size();
        int v[55],h[55];
        for(int i=0;i<n;i++){
            int val = a[i][0];
            for(int j=0;j<m;j++){
                val = max(val, a[i][j]);
            }
            v[i] = val;
        }
        for(int i=0;i<m;i++){
            int val = a[0][i];
            for(int j=0;j<n;j++){
                val = max(val, a[j][i]);
            }
            h[i] = val;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=min(v[i],h[j]) - a[i][j];
            }
        }
        return ans;
    }
};
