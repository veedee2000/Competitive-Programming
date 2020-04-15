class Solution {
    
    // Forming a min-Heap
    
    struct comp{
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second > b.second;  
        }
    };
    
public:
    int shortestSubarray(vector<int>& A, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        int prefix = 0,ans = INT_MAX;
        for(int i = 0;i < A.size();i++){
            prefix += A[i];
            if(prefix >= k) ans = min(ans,i + 1); // This will check if 0 -> i window is a possible answer
            
            while(!pq.empty() and prefix - pq.top().second >= k){ // Keep checking for all the feasible parts
                ans = min(ans,i - pq.top().first); // Update answer when smaller window is found
                pq.pop();
            }
            pq.push({i,prefix}); // Insert the prefix sum of the index i in the heap
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
