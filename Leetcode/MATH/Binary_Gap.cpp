class Solution {
public:
    int binaryGap(int n) {
        int curr = -1,ans = 0;
        for(int i = 31;i >= 0;i--){
            if((1<<i)&n and curr == -1) curr = i;
            else if((1<<i)&n) {ans = max(ans, curr - i), curr = i;}
        }
        return ans;
    }
};
