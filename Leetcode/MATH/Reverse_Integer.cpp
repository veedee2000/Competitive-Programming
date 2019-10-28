class Solution {
public:
    int reverse(int x) {
        double t, rev =0;
        
        while( x != 0){
            t = x%10;
                       
        if( rev > INT_MAX/10  || rev < INT_MIN/10 || rev == INT_MAX || rev == INT_MIN){
            return 0;
        } else{
             rev = t+rev*10;
              x = x/10;
        }
    }
        
        
        return rev;
    }
};
