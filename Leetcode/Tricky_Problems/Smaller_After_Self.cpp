class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>sorted = nums,ans,s;
        sort(sorted.begin(),sorted.end());
        for(int i = 0;i < nums.size();i++){
            int value = nums[i];
            int indexInSorted = upper_bound(sorted.begin(),sorted.end(),value - 1) - sorted.begin();
            int indexInSmall = upper_bound(s.begin(),s.end(),value - 1) - s.begin();
            auto insertInPosition = upper_bound(s.begin(),s.end(),value);
            s.insert(insertInPosition,value);
            if(indexInSorted == nums.size()){
                ans.push_back(0);
            }
            else{
                if(indexInSmall == s.size()){
                    ans.push_back(indexInSorted);
                }
                else{
                    ans.push_back(indexInSorted - indexInSmall);
                }
            }
        }
        return ans;
    }
};
