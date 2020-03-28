class Solution {
public:
    vector<vector<string>>ans;
    int n;
    vector<vector<string>> solveNQueens(int n) {
        this -> n = n;
        unordered_map<int,int>straight,diagPlus,diagMinus;
        f(0,straight,diagPlus,diagMinus,{});
        return ans;
    }
    
    void f(int rem,unordered_map<int,int>&straight,unordered_map<int,int>&diagPlus,unordered_map<int,int>&diagMinus,vector<string>path){
        if(rem == n){
            ans.push_back(path);
            return;
        }
        string line;
        for(int i = 0;i < n;i++) line.push_back('.');
        for(int i = 0;i < n;i++){
            if((!straight.count(i) or !straight[i]) and (!diagPlus.count(rem + i) or !diagPlus[rem + i]) and (!diagMinus.count(rem - i) or !diagMinus[rem - i])){
                line[i] = 'Q';
                straight[i] = 1,diagPlus[rem + i] = 1,diagMinus[rem - i] = 1;
                path.push_back(line);
                f(rem + 1,straight,diagPlus,diagMinus,path);
                path.pop_back();
                straight[i] = 0,diagPlus[rem + i] = 0,diagMinus[rem - i] = 0;
                line[i] = '.';
            }
        }
    }
};
