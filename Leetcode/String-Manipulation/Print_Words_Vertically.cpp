class Solution {
public:
    vector<string> printVertically(string s) {
        int Curr = 0,maxCurr = 0,maxsz = 0;
        for(auto x:s){
            if(x == ' '){
                maxCurr = max(maxCurr,Curr);
                Curr = 0;
                ++maxsz;
            }
            else Curr++;
        }
        ++maxsz;
        maxCurr = max(maxCurr,Curr);
        string blank;
        while(maxsz--){
            blank.push_back(' ');
        }
        vector<string>ans(maxCurr,blank),ansret;
        int val = 0,num = 0;
        for(auto x:s){
            if(x == ' '){
                num = 0;
                val++;
            }
            else{
                ans[num++][val] = x;
            }
        }
        for(auto x:ans){
            int sz = x.size(),p = 0;
            for(int i = sz - 1;i >= 0;i--){
                if(x[i] == ' ') p++;
                else break;
            }
            x.resize(sz - p);
            ansret.push_back(x);
        }
        return ansret;
    }
};
