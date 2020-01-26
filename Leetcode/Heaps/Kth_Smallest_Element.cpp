class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>>heap;
        for(auto x:matrix){
            for(auto y:x){
                heap.push(y);
                if(heap.size() > k) heap.pop();
            }
        }
        return heap.top();
    }
};
