class Solution {
public:
    unordered_map<char,int>mpS,mpT;
    string customSortString(string S, string T) {
        for(auto x:S) mpS[x]++;
        for(auto x:T) mpT[x]++;
        int in = 0;
        for(int i = 0;i < T.size();i++){
            if(mpS[T[i]] and mpT[S[in]]--){
                T[i] = S[in];
                if(mpT[S[in]] < 1) ++in;
            }
        }
        return T;
    }
};
