class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        unordered_map<int,int>mp;
        for(int i = 0;i < nums1.size();i++) mp[nums1[i]] = i;
        stack<int>s;
        for(auto x:nums2){
            while(!s.empty() and x > s.top()){
                ans[mp[s.top()]] = x;
                s.pop();
            }
            if(mp.count(x)) s.push(x); 
        }
        return ans;
    }
};
