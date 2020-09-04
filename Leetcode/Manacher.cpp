class Solution {
public:
    string longestPalindrome(string s) {
        string T = "#";
        for(auto x:s){
            T.push_back(x);
            T.push_back('#');
        }
        int n = T.size();
        vector<int>p(n, 0);
        int center = 0, boundary = 0, maxLength = 0, reqCenter = 0; 
        for(int i = 1;i < n - 1;i++){
            int mirrorCenter = center - (i - center);
            p[i] = (i > boundary) ? 0 : min(p[mirrorCenter], boundary - i);
            while(i - (1 + p[i]) >= 0 and i + (1 + p[i]) < n and T[i - (1 + p[i])] == T[i + (1 + p[i])]) p[i]++;
            if(p[i] > maxLength) maxLength = p[i], reqCenter = i; 
            if(i + p[i] > boundary) center = i, boundary = i + p[i];
        }
        return s.substr((reqCenter - maxLength) / 2, maxLength);
    }
};
