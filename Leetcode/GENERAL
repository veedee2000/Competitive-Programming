class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>>v;
        v.resize(100000,vector<int>(2));
        int n = a.size();
        if(n > 1){
            sort(a.begin(),a.end());
            int ans = 100000;
            for(int i=0;i< n-1;i++){
                ans = min(ans, a[i + 1] - a[i]);
            }
            int p = 0;
            for(int i=0;i< n-1;i++){
                if( (a[i+1] - a[i]) == ans ){
                    v[p][0] = a[i];
                    v[p][1] = a[i+1];
                    p++;
                }
            }
            // cout<<p;
            v.resize(p,vector<int>(2));
            return v;
        }
        else{
            v.resize(1,vector<int>(2));
            return v;
        }
    }
};
