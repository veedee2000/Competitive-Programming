class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i = 0,ans = 0;
        while((1 << i) <= max({a,b,c})){
            if(((1 << i) & c) == (((1 << i) & a) | ((1 << i) & b))){}
            else if(((1 << i) & c)) ans++;
            else{
                if(((1 << i) & a) & ((1 << i) & b)) ans += 2;
                else ans++;
            }
            i++;
        }
        return ans;
    }
};
