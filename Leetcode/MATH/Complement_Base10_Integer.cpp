class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int maxSetBit = 0;
        while((1 << maxSetBit) < N){
            maxSetBit++;
        }
        int ans = 0;
        for(int i = 0;i < maxSetBit;i++){
            if(((1 << i) & N) == 0) ans += (1 << i);
        }
        return ans;
    }
};
