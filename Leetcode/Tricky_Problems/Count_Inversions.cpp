class BIT{
    
    vector<int>bit;
    
public: 
    BIT(int n){
        bit.resize(n + 1,0);
    }
    
    void insert(int i,int val){
        i++;
        while(i < bit.size()){
            bit[i] += val;
            i += i&-i;
        }
    }
    
    int query(int i){
        i++;
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i&-i;
        }
        return sum;
    }
    
};


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int>sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        for(int i = 0;i < nums.size();i++){
            nums[i] = lower_bound(sortedNums.begin(),sortedNums.end(),nums[i]) - sortedNums.begin();
        }
        BIT fenwick(nums.size());
        int ans = 0;
        for(int i = nums.size() - 1;i >= 0;i--){
            ans += fenwick.query(nums[i] - 1); 
            fenwick.insert(nums[i],1);
        }
        return ans;
    }
};
