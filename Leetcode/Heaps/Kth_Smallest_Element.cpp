class Solution {
    
    struct comp{
        bool operator ()(vector<int>a,vector<int>b){
            return a[0] > b[0];
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),ans;
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        for(int i = 0;i < n;i++) pq.push({matrix[0][i],0,i});
        while(k--){
            vector<int>curr = pq.top();
            ans = curr[0];
            pq.pop();
            int x = curr[1],y = curr[2];
            if(x < n - 1) pq.push({matrix[x + 1][y],x + 1,y});
        }
        return ans;
    }
};
