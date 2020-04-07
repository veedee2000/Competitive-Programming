 class NumArray {
    private:
        vector<int>nums,BIT;
      
        int query(int i){
            i++;
            int sum = 0;
            while(i > 0){
                sum += BIT[i];
                i -= i&-i;
            }
            return sum;
        }
        
        void add(int i, int val){
            i++;
            while(i < BIT.size()){
                BIT[i]+=val;
                i += i&-i; 
            }
        }
        
    public:
        NumArray(vector<int> &nums) : nums(nums) {
            BIT.resize(nums.size()+1);
            for(int i = 0;i < nums.size();i++){
                add(i,nums[i]);
            }
        }
    
        void update(int i,int val) {
            if(val != nums[i]){
                add(i,val - nums[i]);
                nums[i]=val;
            }
        }
    
        int sumRange(int i, int j) {
            return query(j) - query(i - 1);
        }
    };
