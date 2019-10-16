class Solution {
public:
    int mySqrt(int x) {
        long long i;
        for(i = 1;i*i < x;i++){
        }
        if(i*i == x) return i;
        else return i-1;
    }
};
