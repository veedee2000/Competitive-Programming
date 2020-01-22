class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>prefix,ans;
        int XOR = 0;
        for(auto x:arr){
            XOR ^= x;
            prefix.push_back(XOR);
        }
        for(auto x:queries){
            if(x[0] == 0) ans.push_back(prefix[x[1]]);
            else ans.push_back(prefix[x[0] - 1] ^ prefix[x[1]]);
        }
        return ans;
    }
};
