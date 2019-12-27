class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int ans = intervals.size();
        int beg = intervals[0][0],end = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(beg <= intervals[i][0] and end >= intervals[i][1]) --ans;
            else beg = intervals[i][0], end = intervals[i][1];
        }
        return ans;
    }
    
    bool static comp(vector<int>a,vector<int>b){
        if(a[0] == b[0]) return (a[1] > b[1]);
        else return (a[0] < b[0]);
    }
};
