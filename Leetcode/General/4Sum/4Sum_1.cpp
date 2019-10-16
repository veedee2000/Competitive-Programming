class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
       set<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i1=0;i1<nums.size();i1++){
            for(int i2=i1+1;i2<nums.size();i2++){
                for(int i3=i2+1;i3<nums.size();i3++){
                    for(int i4=i3+1;i4<nums.size();i4++){
                        if(nums[i1]+nums[i2]+nums[i3]+nums[i4] == target){
                            vector<int>v_new;
                            v_new.push_back(nums[i1]);
                            v_new.push_back(nums[i2]);
                            v_new.push_back(nums[i3]);
                            v_new.push_back(nums[i4]);
                            v.insert(v_new);
                        }
                    }
                }
            }
        }
       int current_size = v.size();
       vector<vector<int>>ans(current_size,vector<int>(0));
       int i=0;
       cout<<current_size;
        for(auto x:v){
            ans[i] = x;
            ++i;
        }
        return ans;
    }
};
