class Solution {
public:
    int countElements(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int i = 0;i < arr.size();i++){
            auto lb = lower_bound(arr.begin() + i,arr.end(),arr[i] + 1);
            if(lb != arr.end() and *lb == arr[i] + 1) ans++;
        }
        return ans;
    }
};
