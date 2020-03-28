class Solution {
public:
    vector<vector<string>>ans;
    int n;
    vector<vector<string>> solveNQueens(int n) {
        this -> n = n;
        vector<vector<bool>>b(n,vector<bool>(n,0));
        f(0,b,{});
        return ans;
    }
    
    void f(int rem,vector<vector<bool>>&b,vector<string>path){
        if(rem == n){
            ans.push_back(path);
            return;
        }
        string line;
        for(int i = 0;i < n;i++) line.push_back('.');
        for(int i = 0;i < n;i++){
            if(!b[rem][i]){
                line[i] = 'Q';
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
                path.push_back(line);
                f(rem + 1,bNew,path);
                path.pop_back();
                line[i] = '.';
            }
        }
    }
};
