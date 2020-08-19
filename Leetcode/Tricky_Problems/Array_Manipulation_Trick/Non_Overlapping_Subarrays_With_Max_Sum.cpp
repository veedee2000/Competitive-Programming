class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int>rightL(n), rightM(n);
        int sumL = nums[n - 1], sumM = nums[n - 1];
        rightL[n - 1] = rightM[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--){
            sumL += nums[i], sumM += nums[i];
            if(n - i > L) sumL -= nums[n - (n - i - L)];
            if(n - i > M) sumM -= nums[n - (n - i - M)];
            rightL[i] = max(rightL[i + 1], sumL);
            rightM[i] = max(rightM[i + 1], sumM);
        }
        int ans = INT_MIN, leftL = 0, leftM = 0;
        sumM = sumL = 0;
        for(int i = 0;i < n - M;i++){
            sumL += nums[i];
            if(i < L - 1) continue;
            leftL = max(leftL, sumL);
            ans = max(ans, leftL + rightM[i + 1]);
            sumL -= nums[i - L + 1];
        }
        for(int i = 0;i < n - L;i++){
            sumM += nums[i];
            if(i < M - 1) continue;
            leftM = max(leftM, sumM);
            ans = max(ans, leftM + rightL[i + 1]);
            sumM -= nums[i - M + 1];
        }
        return ans;
    }
};
