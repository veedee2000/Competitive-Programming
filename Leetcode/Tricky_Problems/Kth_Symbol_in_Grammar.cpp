class Solution {

public:
  
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        int bit =  K&1;
        if(!bit) return kthGrammar(N - 1, (K + 1) / 2) ? 0 : 1;
        else return kthGrammar(N - 1, (K + 1) / 2) ? 1 : 0;
    }
};
