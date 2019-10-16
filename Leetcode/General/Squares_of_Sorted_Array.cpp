class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        vector<int>v;
        for(auto x:a) v.push_back(x*x);
        sort(v.begin(),v.end());
        return v;
    }
};
