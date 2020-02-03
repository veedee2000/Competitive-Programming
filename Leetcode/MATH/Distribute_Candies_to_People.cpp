class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int i = 0,val = 1;
        while(candies > 0){
            ans[i] += min(candies,val);
            candies -= min(candies,val);
            val++;
            i = (i + 1) % num_people;
        }
        return ans;
    }
};
