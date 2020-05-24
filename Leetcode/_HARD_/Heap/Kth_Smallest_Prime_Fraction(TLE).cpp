class Solution {
    
    struct comp{
        bool operator()(vector<double>& a,vector<double>& b){
            return a[0] > b[0];
        }
    };
    
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<vector<double>,vector<vector<double>>,comp>heap;
        int n = A.size();
        for(int i = 0;i < A.size() - 1;i++) heap.push({(double) A[i] / A[n - 1],(double) i,(double) n - 1});
        while(--K){
            vector<double>curr = heap.top();
            heap.pop();
            int row = (int) curr[1], col = (int) curr[2] - 1;
            if(col > row) heap.push({(double) A[row] / A[col],(double) row,(double) col});
        }
        return {A[(int) heap.top()[1]], A[(int) heap.top()[2]]};
    }
};
