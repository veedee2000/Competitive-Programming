class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>ans;
        vector<int>ret;
        for(auto x:restaurants){
            if(!(veganFriendly == 1 and x[2] == 0)){
                if(maxPrice >= x[3] and maxDistance >= x[4]) ans.push_back({x[0],x[1]});
            }
        }
        sort(ans.begin(),ans.end(),comp);
        for(auto x:ans) ret.push_back(x[0]);
        return ret;
    }
    
    bool static comp(vector<int>a,vector<int>b){
        if(a[1] != b[1]) return a[1] > b[1];
        return a[0] > b[0];
    }
};
