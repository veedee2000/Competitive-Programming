class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxVal = INT_MIN;

        for(int L = 0;L < n;L++){
            vector<int>currArray(m,0);
            for(int R = L;R < n;R++){
                for(int i = 0;i < m;i++) currArray[i] += matrix[i][R];
                int prefix = 0;
                set<int>s;
                s.insert(0);
                for(int i = 0;i < m;i++){
                    prefix += currArray[i];
                    auto it = s.lower_bound(prefix - k);
                    if(it != s.end()) maxVal = max(maxVal, prefix - *it);
                    s.insert(prefix);
                }
            }
        }

        return maxVal;
    }
};
