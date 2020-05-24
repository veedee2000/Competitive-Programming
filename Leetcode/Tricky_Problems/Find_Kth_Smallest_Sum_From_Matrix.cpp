class Solution {
    
    struct comp{
        bool operator()(vector<int>& a,vector<int>& b){
            return a[0] > b[0];
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comp>heap;
        int m = mat.size(), n = mat[0].size();
        if(m == 1) return mat[0][k - 1];
        vector<int>list = mat[0], aux;
        int sub, lastElement;
        for(int i = 1;i < m;i++){
            sub = k;
            for(int j = 0;j < list.size();j++){
                heap.push({list[j] + mat[i][0],j,0});
            }
            while(sub-- and !heap.empty()){
                lastElement = heap.top()[0];
                aux.push_back(lastElement);
                int row = heap.top()[1], col = heap.top()[2] + 1;
                heap.pop();
                if(col < n) heap.push({list[row] + mat[i][col],row,col});
            }
            list = aux;
            aux.clear();
            heap = priority_queue<vector<int>,vector<vector<int>>,comp>();
        }
        return lastElement;
    }
};
