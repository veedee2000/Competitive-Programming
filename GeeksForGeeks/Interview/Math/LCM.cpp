long long f(int base,int exp){
    if(exp == 0) return 1;
    else if(exp&1) return base * f(base,exp / 2) * f(base,exp / 2);
    else return f(base, exp / 2) * f(base, exp / 2);
}

long long getSmallestDivNum(long long n){
    long long ans = 1;
    vector<int> primes = {2,3,5,7,11,13,17,19,23};
    vector<int>v(primes.size(),0);
    int x, val;
    for(int i = 2;i <= n;i++){
        x = i;
        for(int j = 0;j < primes.size();j++){
            val = 0;
            while(x >= primes[j] and (x % primes[j] == 0)){
                x /= primes[j];
                val++;
            }
            v[j] = max(v[j],val);
        }
    }
    for(int i = 0;i < primes.size();i++){
        ans *= f(primes[i],v[i]);
    }
    return ans;
}
