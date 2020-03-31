class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = A.size(),m = B.size(),i,j;
        vector<int>lps(m,0);
        i = 1,j = 0;
        while(i < m){
            if(B[i] == B[j]) lps[i++] = ++j;
            else if(j != 0) j = lps[j - 1];
            else i++;
        }
        
        i = 0,j = 0;
        while(i < n){
            if(A[(i + j) % n] == B[j]) j++;
            if(j == m){
                return (i + j) % n ? (i + j) / n + 1 : (i + j) / n;
            }
            else if(i < n and A[(i + j) % n] != B[j]){
                if(j){
                    i += j - lps[j - 1];
                    j = lps[j - 1];
                }
                else i++;
            }
        }
        return -1;
    }
};
