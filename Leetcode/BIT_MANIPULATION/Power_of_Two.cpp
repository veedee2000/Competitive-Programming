class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        if(n < 1) return false;
        for(int i = 31; i>=0;i--){
            if((1<<i) & n) c++;
        }
        if(c == 1) return true;
        return false;
    }
};
