class BIT{
    
    vector<int>bit;
    
public: 
    BIT(int n){
        bit.resize(n + 1,0);
    }
    
    void insert(int i){
        i++;
        while(i < bit.size()){
            bit[i] ++;
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
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        int n = nums.size();
        for(int i = 0;i < n;i++){
            nums[i] = lower_bound(sortedNums.begin(),sortedNums.end(),nums[i]) - sortedNums.begin();
        }
        BIT fenwick(n);
        vector<int>ans(n);
        for(int i = n - 1;i >= 0;i--){
            ans[i] = fenwick.query(nums[i] - 1); 
            fenwick.insert(nums[i]);
        }
        return ans;
    }
};
