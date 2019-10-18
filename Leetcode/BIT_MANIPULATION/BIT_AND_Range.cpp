class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        bool check = 0;
        int c1=0,c2=0;
        for(int i = 31; i>=0;i--){
            if((1<<i)&m) {c1 = i; break;}
        }
        
        for(int i = 31; i>=0;i--){
            if((1<<i)&n) {c2 = i; break;}
        }
        
        if(c1 != c2) return 0;
        
        for(int i = c1; i>=0;i--){
            // cout<<((1<<i)&m)<<" "<<((1<<i)&n)<<endl;
            if( ((1<<i)&m) == ((1<<i)&n) ) ans += ((1<<i)&m);
            else break;
        }
        return ans;
    }
};
