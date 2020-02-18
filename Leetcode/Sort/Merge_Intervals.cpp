class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size()) return {};
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),comp);
        int start = -1,end;
        for(auto x:intervals){
            if(start == -1) start = x[0],end = x[1];
            else{
                if(x[0] <= end) end = max(end,x[1]);
                else{
                    ans.push_back({start,end});
                    start = x[0],end = x[1];
                }
            }
        }
        ans.push_back({start,end});
        return ans;
    }
    
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0] < b[0];
    }
};
