class Solution {
public:
    vector<int>ans;
    vector<int> pathInZigZagTree(int label) {
        int num = lo_pow(label);
        int count = num + 1;
        while(count--){
            int shift = (label - (1 << num)) / 2;
            ans.push_back(label);
            label = (1 << num) - 1 - shift;
            num = lo_pow(label);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int lo_pow(int x){
        if(x < 2) return 0;
        return 1 + lo_pow(x >> 1);
    }
    
};
