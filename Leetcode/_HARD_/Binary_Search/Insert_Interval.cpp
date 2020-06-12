class Solution {
    
    int lowerBound(int target,vector<vector<int>>& intervals){
        int l = 0, r = intervals.size() - 1, m, ans = intervals.size();
        while(l <= r){
            m = l + (r - l) / 2;
            if(intervals[m][1] >= target) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
    
    int upperBound(int target,vector<vector<int>>& intervals){
        int l = 0, r = intervals.size() - 1, m, ans = -1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(intervals[m][0] <= target) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int startIndex = lowerBound(newInterval[0],intervals), endIndex = upperBound(newInterval[1],intervals);
        if(endIndex < startIndex){
            auto it = intervals.begin();
            advance(it,startIndex);
            intervals.insert(it,newInterval);
        }
        else if(endIndex == -1){
            intervals.insert(intervals.begin(),newInterval);
        }
        else if(startIndex == intervals.size()){
            intervals.insert(intervals.end(),newInterval);
        }
        else{
            int begin = min(intervals[startIndex][0],newInterval[0]), end = max(intervals[endIndex][1],newInterval[1]);
            auto itBegin = intervals.begin(), itEnd = intervals.begin();
            advance(itBegin,startIndex), advance(itEnd,endIndex + 1);
            intervals.erase(itBegin,itEnd);
            auto itInsert = intervals.begin();
            advance(itInsert,startIndex);
            intervals.insert(itInsert,{begin,end});
        }
        return intervals;
    }
};
