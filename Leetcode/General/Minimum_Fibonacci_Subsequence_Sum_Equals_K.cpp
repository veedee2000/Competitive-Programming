class Solution {
    
    vector<long long>fib;
    int lowerBound(int val){
        int l = 0,r = fib.size() - 1,m,ans;
        while(l <= r){
            m = l + (r - l) / 2;
            if(fib[m] == val) return val;
            else if(fib[m] < val) l = m + 1,ans = fib[m];
            else r = m - 1;
        }
        return ans;
    }
    
public:
    int findMinFibonacciNumbers(int k) {
        long long val;
        fib.push_back(1);
        fib.push_back(1);
        for(int i = 2;i < 50;i++){
            val = fib[i - 1] + fib[i - 2];
            if(val > k) break;
            fib.push_back(val);
        }
        int ans = 0,index;
        while(k){
            k -= lowerBound(k);
            ++ans;
        }
        return ans;
    }
};
