class Solution {
public:
    int ans;
    int n;
    int totalNQueens(int n) {
        this -> n = n;
        unordered_map<int,int>straight,diagPlus,diagMinus;
        f(0,straight,diagPlus,diagMinus);
        return ans;
    }
    
    void f(int rem,unordered_map<int,int>&straight,unordered_map<int,int>&diagPlus,unordered_map<int,int>&diagMinus){
        if(rem == n){
            ans++;
            return;
        }
        for(int i = 0;i < n;i++){
            if((!straight.count(i) or !straight[i]) and (!diagPlus.count(rem + i) or !diagPlus[rem + i]) and (!diagMinus.count(rem - i) or !diagMinus[rem - i])){
                straight[i] = 1,diagPlus[rem + i] = 1,diagMinus[rem - i] = 1;
                f(rem + 1,straight,diagPlus,diagMinus);
                straight[i] = 0,diagPlus[rem + i] = 0,diagMinus[rem - i] = 0;
            }
        }
    }
};
