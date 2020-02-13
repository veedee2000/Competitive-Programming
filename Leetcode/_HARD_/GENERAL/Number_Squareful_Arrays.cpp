class Solution {
public:
    int ans,n;
    unordered_map<string,bool>mp;
    vector<int>A;
    int numSquarefulPerms(vector<int>& A) {
        this -> A = A;
        ans = 0,n = A.size();
        f(0,{},0,"");
        return ans;
    }
    
    void f(int hash,vector<int>v,int sz,string s){
        if(sz == n){
            double val = v[v.size() - 2] + v[v.size() - 1];
            if(sqrt(val) == (int) sqrt(val)){
                ++ans;
                for(auto x:v) cout<<x<<" ";
                cout<<endl;
            }
            return;
        }
        for(int i = 0;i < n;i++){
            if((hash & (1 << i)) == 0){
                int hashPass = hash | (1 << i);
                if(mp.count(s + to_string(A[i]) + ",")) continue;
                v.push_back(A[i]);
                mp[(s + to_string(A[i]) + ",")] = 1;
                if(v.size() > 1){
                    double val = v[v.size() - 2] + v[v.size() - 1];
                    if(sqrt(val) == (int) sqrt(val)) f(hashPass,v,sz + 1,s + to_string(A[i]) + ",");
                }
                else f(hashPass,v,sz + 1,s + to_string(A[i]) + ",");
                v.pop_back();
            }
        }
    }
    
};
