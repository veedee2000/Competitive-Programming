class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i = 31;i >= 0;i--){
            if(((1 << i) & m) ^ ((1 << i) & n)) break;
            if((1 << i) & m) ans |= (1 << i); 
        }
        return ans;
    }
};
