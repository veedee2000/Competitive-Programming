class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == -1) return 1/x;
        else if(n%2 == 0) return myPow(x,n/2) * myPow(x,n/2);
        else if(n%2 == 1 and n > 0) return x * myPow(x,n/2) * myPow(x,n/2);
        else return myPow(x,n/2) * myPow(x,n/2) * (1 / x);
    }
};
