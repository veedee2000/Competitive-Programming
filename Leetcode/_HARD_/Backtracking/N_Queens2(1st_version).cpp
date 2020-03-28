class Solution {
public:
    int ans;
    int n;
    int totalNQueens(int n) {
        this -> n = n;
        vector<vector<bool>>b(n,vector<bool>(n,0));
        f(0,b);
        return ans;
    }
    
    void f(int rem,vector<vector<bool>>&b){
        if(rem == n){
            ans++;
            return;
        }
        for(int i = 0;i < n;i++){
            if(!b[rem][i]){
                vector<vector<bool>>bNew = b;
                for(int j = rem + 1;j < n;j++){
                    bNew[j][i] = 1;
                }
                int in = 1;
                while(max(rem + in,i + in) < n){
                    bNew[rem + in][i + in] = 1;
                    in++;
                }
                in = 1;
                while(rem + in < n and i - in >= 0){
                    bNew[rem + in][i - in] = 1;
                    in++;
                }
                f(rem + 1,bNew);
            }
        }
    }
};
