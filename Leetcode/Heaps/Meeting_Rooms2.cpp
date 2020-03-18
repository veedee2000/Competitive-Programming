/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    
    struct comp{
        bool operator()(Interval &a,Interval &b){
            if(a.start <= b.start and a.end >= b.end) return 1;
            if(b.start <= a.start and b.end >= a.end) return 0;
            return a.start > b.start;
        }
    };
    
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        if(!intervals.size()) return 0;
        sort(intervals.begin(),intervals.end(),compare);
        priority_queue<Interval,vector<Interval>,comp>pq;
        int ans = 1,l = intervals[0].start,r = intervals[0].end;
        pq.push({intervals[0].start,intervals[0].end});
        int index = 1;
        while(!pq.empty() and index < intervals.size()){
            while(pq.size() and r <= intervals[index].start){
                pq.pop();
                l = pq.top().start,r = pq.top().end;
            }
            pq.push(intervals[index++]);
            l = pq.top().start,r = pq.top().end;
            // cout<<l<<" "<<r<<endl;
            ans = max(ans,(int) pq.size());
        }
        return ans;
    }
    
    bool static compare(Interval &a,Interval&b){
        if(a.start != b.start) return a.start < b.start;
        return a.end > b.end;
    }
};
