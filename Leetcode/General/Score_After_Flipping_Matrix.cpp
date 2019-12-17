class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size() == 0) return 0;
        for(int i = 0;i < A.size();i++){
            if(A[i][0] == 0){
                for(int j = 0;j < A[i].size();j++){
                    A[i][j] = !A[i][j];
                }
            }
        }
        for(int j = 1;j < A[0].size();j++){
            int sum = 0;
            for(int i = 0;i < A.size();i++){
                sum += A[i][j];
            }
            if(2 * sum < A.size()){
                for(int i = 0;i < A.size();i++){
                    A[i][j] = !A[i][j];
                }
            }
        }
        int ans = 0;
        
        for(int i = 0;i < A.size();i++){
            for(int j = A[0].size() - 1;j >= 0;j--){
                if(A[i][j]) ans += (1<<(A[0].size() - 1 - j));
            }
        }
        return ans;
    }
};
