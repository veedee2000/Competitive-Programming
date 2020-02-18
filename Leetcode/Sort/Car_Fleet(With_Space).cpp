class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        int n = position.size();
        vector<pair<int,int>>v;
        for(int i = 0;i < n;i++) v.push_back({position[i],speed[i]});
        sort(v.begin(),v.end(),comp);
        double saved = (double) (target - v[n - 1].first) / v[n - 1].second,ans = 0;
        for(int i = n - 2;i >= 0;i--){
            double curr = (double) (target - v[i].first) / v[i].second;
            if(saved < curr) ++ans,saved = curr;  
        }
        ans++;
        return ans;
    }
    
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return (a.first < b.first);
    }
};
