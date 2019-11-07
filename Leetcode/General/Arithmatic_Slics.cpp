class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int>v(A.size(), INT_MIN);
        for(int i = 1;i < A.size();i++){
            v[i - 1] = A[i] - A[i - 1];
        }
        int c = 0,val = INT_MIN,ans = 0;
        for(auto x:v){
            if(val == x) c++;
            else{
                val = x;
                ans += c*(c - 1)/2;
                c = 1;
            }
        }
        ans += c*(c - 1)/2;
        return ans;
    }
};
