class Solution {
    
    void merge(vector<vector<int>>& left, vector<vector<int>>& right, vector<vector<int>>& numsIndex, vector<int>& ans){
        int m = left.size(), n = right.size();
        int i = 0, j = 0, k = 0, count = 0;
        while(i < m and j < n){
            if(left[i][0] <= right[j][0]) numsIndex[k] = left[i], ans[left[i][1]] += count, i++;
            else numsIndex[k] = right[j], ++count, j++;
            k++;
        }
        while(i < m) numsIndex[k] = left[i], ans[left[i][1]] += count, i++, k++;
        while(j < n) numsIndex[k++] = right[j++];
    }
    
    void mergeSort(vector<vector<int>>& numsIndex, vector<int>& ans){
        int n = numsIndex.size(), m = n / 2;
        if(n < 2) return;
        vector<vector<int>>left, right;
        for(int i = 0;i < m;i++) left.push_back(numsIndex[i]);
        for(int i = m;i < n;i++) right.push_back(numsIndex[i]);
        mergeSort(left, ans);
        mergeSort(right, ans);
        merge(left, right, numsIndex, ans);
        left.clear();
        right.clear();
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        vector<vector<int>>numsIndex;
        for(int i = 0;i < n;i++) numsIndex.push_back({nums[i], i});
        mergeSort(numsIndex, ans);
        return ans;
    }
};
