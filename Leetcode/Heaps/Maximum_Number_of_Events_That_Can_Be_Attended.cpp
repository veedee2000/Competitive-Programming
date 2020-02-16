class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 0,i = 0;
        for(int d = 1;d <= 100000;d++){
            while(i < events.size() and events[i][0] == d){
                pq.push(events[i++][1]);
            }
            while(pq.size() and pq.top() < d){
                pq.pop();
            }
            if(pq.size()){
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
    
};
