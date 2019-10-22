class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[s.size() + 20][200];
        if(s.size() == 0) return 0;
        if(s[0] == ' ') return 1;
        for(int i=0;i < s.size();i++){
            for(int j=0;j < 150;j++){
                if(i == 0){
                    if(j == s[i] - ' ') alpha[i][j] = 1;
                    else alpha[i][j] = 0;
                }
                else{
                    if(j == s[i] - ' ') alpha[i][j] = alpha[i-1][j] + 1;
                    else alpha[i][j] = alpha[i-1][j];
                }
            }
        }
        int ans=0;
        int i = 0,j = 0;
        while(j < s.size()){
            bool check = 1;
            for(int k = 0;k < 150;k++){
                if(j == 0) ans = max(ans, 1);
                else if(i == 0){
                    if(alpha[j][k] > 1) {check = 0; break;} 
                }
                else{
                    if(alpha[j][k] - alpha[i - 1][k] > 1) {check = 0; break;}
                }
            }
            if(check) {ans = max(ans, j - i + 1); j++;}
            else i++;
        }
        return ans;
    }
};
