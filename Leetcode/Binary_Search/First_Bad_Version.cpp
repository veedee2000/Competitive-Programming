// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n,m;
        if(n == 1) return 1;
        while(l < r){
            m = l + (r - l)/2;
            if(l == r - 1){
                if(isBadVersion(l)) return l;
                else return r;
            }
            if(!isBadVersion(m)) l = m;
            else r = m;
        }
        return 0;
    }
};
