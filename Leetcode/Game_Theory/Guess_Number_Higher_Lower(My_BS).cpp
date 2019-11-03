// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n,m;
        if(n == 1) return 1;
        while(l < r){
            m = l + (r - l)/2;
            if(l == r - 1){
                if(!guess(l)) return l;
                else return r;
            }
            if(guess(m) < 0) r = m;
            else if(guess(m) > 0) l = m;
            else return m;
        }
        return 1;
    }
};
