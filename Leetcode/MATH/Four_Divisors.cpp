class Solution {
    
    const int n = 100010;
    vector<bool>prime;
    
    void SieveOfEratosthenes(){ 
        for(int p = 2;p*p < n;p++){ 
            if(prime[p] == 1){
                for (int i = p*p;i < n;i += p) prime[i] = 0; 
            }
        }
    } 
    
public:
    
    int sumFourDivisors(vector<int>& nums) {
        prime.resize(n,1);
        vector<int>allPrimes;
        SieveOfEratosthenes();
        prime[0] = 0,prime[1] = 0;
        for(int i = 2;i < prime.size();i++){
            if(prime[i]) allPrimes.push_back(i);
        }
        int ans = 0;
        for(auto num:nums){
            for(auto x:allPrimes){
                if(x * x > num) break;
                if(num % x == 0 and num / x != x and prime[num / x]){
                    ans += 1 + num + x + num / x;
                    break;
                }
                if(x * x * x == num){
                    ans += 1 + x + x * x + x * x * x;
                    break;
                }
            }
        }
        return ans;
    }
};
