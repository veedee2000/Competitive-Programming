class Solution {
public:
    string shortestPalindrome(string s) {
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
        int sz = 0;
        for(int i = 2;i < modifiedS.size() - 1;i++){
            if(P[i] >= sz and ((i - 3 + (i - 1) % 2) / 2 - (P[i] - 1) / 2) == 0){
                sz = P[i];
            }
        }
        string add = s.substr(sz);
        reverse(add.begin(),add.end());
        return add + s;
    }
};
