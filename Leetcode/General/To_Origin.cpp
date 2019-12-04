class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans(k,vector<int>(0));
        vector<pair<int,int>>v;
        for(int i = 0;i < points.size();i++){
            int val = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({val,i});
        }
        sort(v.begin(),v.end(),comp);
        for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
        for(int i = 0;i < k;i++){
            int l = points[v[i].second][0];
            int r = points[v[i].second][1];
            ans[i].push_back(l);
            ans[i].push_back(r);
        }
        return ans;
    }
    
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.first < b.first;
    }
};
