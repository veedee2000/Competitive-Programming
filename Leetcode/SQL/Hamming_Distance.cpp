class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            if(((1<<i)&x) > 0 and ((1<<i)&y) == 0) ++ans;
            else if(((1<<i)&x) == 0 and ((1<<i)&y) > 0) ++ans;
        }
        return ans;
    }
};
