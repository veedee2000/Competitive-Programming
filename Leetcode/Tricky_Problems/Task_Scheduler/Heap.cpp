class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto x:tasks) mp[x]++;
        priority_queue<int>pq;
        for(auto x:mp) pq.push(x.second);
        int totalTime = 0;
        while(!pq.empty()){
            vector<int>aux;
            for(int i = 0;i <= n and !pq.empty();i++){
                aux.push_back(pq.top() - 1);
                pq.pop();
            }
            for(auto x:aux) if(x) pq.push(x);
            if(pq.empty()) totalTime += aux.size();
            else totalTime += max(n + 1,(int) aux.size());
        }
        return totalTime;
    }
};
