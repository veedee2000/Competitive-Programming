class Solution {
public:
    int findComplement(int num) {
        int i;
        for(i = 31;i>=0;i--){
            if((1<<i)&num) break;
        }
        int ans=0;
        for(int j = i;j>=0;j--){
            if((1<<j)&num) ans = ans << 1;
            else ans = (ans << 1) | 1;
        }
        return ans;
    }
};
