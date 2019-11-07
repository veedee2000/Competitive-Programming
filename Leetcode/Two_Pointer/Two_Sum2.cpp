class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0,r = numbers.size() - 1;
        vector<int>v;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                v.push_back(++l);
                v.push_back(++r);
                return v;
            }
            else if(numbers[l] + numbers[r] < target) l++;
            else r--;
        }
        return v;
    }
};
