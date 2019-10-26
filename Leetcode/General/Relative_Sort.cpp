class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        set<int>s;
        vector<int>ans;
        map<int,int>mp;
        for(auto x:arr1) s.insert(x),mp[x]++;
        int i = 0;
        while(i < arr2.size()){
            s.erase(arr2[i]);
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
            ++i;
        }
        for(auto x:s){
            while(mp[x]--)
            ans.push_back(x);
        }
        return ans;
    }
};
