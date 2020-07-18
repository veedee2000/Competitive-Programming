class Solution {
    
    void merge(int l, int m, int r, int A[], int& ans){
        int i = l, j = m;
        for(j = m;j <= r;j++){
            while(i < m and A[i] <= (long) 2 * A[j]) i++;
            if(i == m) break;
            ans += m - i;
        }
        i = l, j = m;
        int k = 0;
        int temp[r - l + 1];
        while(i < m and j <= r){
            if(A[i] <= A[j]) temp[k++] = A[i++];
            else temp[k++] = A[j++];
        }
        while(i < m) temp[k++] = A[i++];
        while(j <= r) temp[k++] = A[j++];
        
        for(int k = l;k <= r;k++) A[k] = temp[k - l];
    }
    
    void mergeSort(int l, int r, int A[], int& ans){
        if(l >= r) return;
        int m = l + (r - l + 1) / 2;
        mergeSort(l, m - 1, A, ans);
        mergeSort(m, r, A, ans);
        merge(l, m, r, A, ans);
    }
    
    
    
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(!n) return 0;
        int A[n];
        for(int i = 0;i < n;i++) A[i] = nums[i]; 
        mergeSort(0, n - 1, A, ans);
        return ans;
    }
};
