class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int>ans;
        for(auto x:a){
            if(x%2 == 0) ans.push_back(x);
        }
        for(auto x:a){
            if(x%2 != 0) ans.push_back(x);
        }
        return ans;
    }
};
