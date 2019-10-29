class Solution {
public:
    int trailingZeroes(int n) {
        long long div = 5,ans = 0;
        while(n/div){
            ans += n/div;
            div *= 5;
        }
        return ans;
    }
};
