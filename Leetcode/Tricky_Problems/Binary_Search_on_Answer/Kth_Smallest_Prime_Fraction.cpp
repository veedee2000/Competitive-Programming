class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        int n = A.size();
        sort(A.begin(), A.end());
        double smallest = A[0] / A[n - 1], val;
        double l = smallest, r = 1, mid;
        int count, i, j;
        vector<int>ans;
        while(1){
            mid = l + (r - l) / 2;
            count = 0, j = 1;
            val = smallest;
            for(i = 0;i < n - 1;i++){
                j = max(j, i + 1);
                while(j < n and (double) A[i] / A[j] > mid) j++;
                if(j < n and (double) A[i] / A[j] > val) ans = {A[i], A[j]}, val = (double) A[i] / A[j]; 
                count += n - j;
            }
            if(count == k) break;
            else if(count > k) r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};
