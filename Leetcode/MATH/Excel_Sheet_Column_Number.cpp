class Solution {
public:
    int titleToNumber(string s) {
        int sz = s.size() - 1,ans = 0;
        int  power = binExp(26,sz);
        for(auto x:s){
            ans += power * (x - 'A' + 1);
            power /= 26;
        }
        return ans;
    }
    
    int binExp(int a,int exp){
        if(exp == 0) return 1;
        if(exp & 1) return a * binExp(a,exp / 2) * binExp(a,exp / 2);
        else return binExp(a,exp / 2) * binExp(a,exp / 2);
    }
};
