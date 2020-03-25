class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return 0;
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums){
            if(!mp.count(x)) pq.push(x);
            mp[x]++;
        }
        while(!pq.empty()){
            int start = pq.top();
            for(int i = start;i < start + k;i++){
                if(!mp.count(i) or mp[i] == 0) return 0;
                if(--mp[i] == 0){
                    if(pq.top() != i) return 0;
                    pq.pop();
                }
            }
        }
        return 1;
    }
};
