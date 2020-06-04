class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSubarray = A[0], minSubarray = A[0], currMax = 0, currMin = 0, total = 0;
        for(auto x:A){
            currMax = max(currMax + x,x);
            currMin = min(currMin + x,x);
            
            maxSubarray = max(maxSubarray, currMax);
            minSubarray = min(minSubarray, currMin);
            total += x;
        }
        return total == minSubarray ? maxSubarray : max(maxSubarray,total - minSubarray);
    }
};
