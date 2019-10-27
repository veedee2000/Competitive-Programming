class Solution {
public:
    int smallestRangeI(vector<int>& a, int k) {
        int mmin = a[0], mmax = a[0];
        for(auto x:a){
            mmin = min(mmin, x);
            mmax = max(mmax, x);
        }
        if(mmax - mmin - 2 * k > 0) return mmax - mmin - 2 * k;
        else return 0;
    }
};
