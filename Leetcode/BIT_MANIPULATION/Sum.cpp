class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, carry = 0;
        for(int i = 0;i < 32;i++){
            int bit1 = (a & (1 << i)) != 0, bit2 = (b & (1 << i)) != 0;
            if(carry) ans |= (bit1 ^ bit2) ? 0 : (1 << i), carry = bit1 | bit2;
            else ans |= (bit1 ^ bit2) ? (1 << i) : 0, carry = bit1 & bit2;
        }
        return ans;
    }
};
