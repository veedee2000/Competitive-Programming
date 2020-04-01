class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        string modifiedS = "$";
        for(auto x:s){
            modifiedS += "#";
            modifiedS.push_back(x);
        }
        modifiedS += "#@";
        vector<int>P(modifiedS.size(),0);
        int C = 0,R = 0;
        for(int i = 1;i < modifiedS.size() - 1;i++){
            int mirr = 2 * C - i;
            if(i < R) P[i] = min(R - i,P[mirr]);
            
            while(modifiedS[i + (1 + P[i])] == modifiedS[i - (1 + P[i])]) P[i]++;
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        int ansIndex,sz = 0;
        bool c; // 0 for even, 1 for odd
        for(int i = 2;i < modifiedS.size() - 1;i++) cout<<P[i]<<" ";
        for(int i = 2;i < modifiedS.size() - 1;i++){
            if(P[i] > sz){
                sz = P[i];
                ansIndex = i;
                if((i - 1) % 2) c = 1;
                else c = 0;
            }
        }
        return c ? s.substr((ansIndex - 2) / 2 - (sz - 1) / 2,sz) : s.substr((ansIndex - 3) / 2 - (sz - 1) / 2,sz);
    }
};
