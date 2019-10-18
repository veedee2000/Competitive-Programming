class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        long long val=1;
        for(int i = 30;i>0;i--){
            if(val == n) return true;
            if(val > n) return false;
            val *= 3;
        }
        return false;
    }
};
