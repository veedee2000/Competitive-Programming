class Solution {
public:
    bool isHappy(int n) {
        int count = 1e5 + 5000,val = 0;
        while(count--){
            if(n == 1) return 1;
            while(n){
                val += (n % 10) * (n % 10);
                n /= 10;
            }
            n = val;
            val = 0;
        }
        return 0;
    }
};
