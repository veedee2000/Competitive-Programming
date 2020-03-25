class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return 0;
        unordered_map<int,int>mp;
        // priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>pq;
        for(auto x:nums){
            if(!mp.count(x)) pq.push_back(x);
            mp[x]++;
        }
        sort(pq.begin(),pq.end(),comp);
        int sz = pq.size();
        while(!pq.empty()){
            int start = pq[sz - 1];
            for(int i = start;i < start + k;i++){
                if(!mp.count(i) or mp[i] == 0) return 0;
                if(--mp[i] == 0){
                    if(pq[sz - 1] != i) return 0;
                    pq.pop_back();
                    sz--;
                }
            }
        }
        return 1;
    }
    
    bool static comp(int &a,int &b){
        return a > b;
    }
};
