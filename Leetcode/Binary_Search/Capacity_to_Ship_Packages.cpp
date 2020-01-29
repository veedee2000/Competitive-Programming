class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 1,right = 50000,ans;
        while(left <= right){
            cout<<left<<" "<<right<<endl;
            int mid = left + (right - left) / 2;
            int sum = 0,d = 0;
            bool c = 0;
            for(auto x:weights){
                if(x > mid) {c = 1; break;}
                sum += x;
                if(sum > mid){
                    sum = x;
                    d++;
                }
            }
            d++;
            if(d > D or c) left = mid + 1;
            else right = mid - 1,ans = mid;
        }
        return ans;
    }
};
