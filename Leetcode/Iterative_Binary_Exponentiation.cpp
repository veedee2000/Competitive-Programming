int binExpo(long long a, int b){
    long long result = 1;
    while(b > 0){
        if(b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
