class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left;i <= right;i++){
            int now = i,rem;
            bool c = 1;
            while(now > 0){
                rem = now % 10;
                now /= 10;
                if(rem == 0) {c = 0; break;}
                if(i%rem != 0) {c = 0; break;}
            }
            if(c) ans.push_back(i);
        }
        return ans;
    }
};
