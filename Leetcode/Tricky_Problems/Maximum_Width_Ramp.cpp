class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int MIN = A[0],ans = 0;
        vector<vector<int>>lesser = {{MIN,0}};
        for(int i = 1;i < A.size();i++){
            int smallestIndex = binSearch(lesser,A[i]);
            if(smallestIndex != -1) ans = max(ans,i - smallestIndex);
            if(A[i] < MIN){
                lesser.push_back({A[i],i});
                MIN = A[i];
            }
        }
        return ans;
    }
    
    int binSearch(vector<vector<int>>&v,int val){
        int l = 0,r = v.size() - 1,m,ans = -1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(v[m][0] == val) return v[m][1];
            else if(v[m][0] < val) ans = v[m][1],r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
