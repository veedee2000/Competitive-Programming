class Solution {
public:
    int n,m;
    bool check[100][100];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        if(n == 0) return image;
        m = image[0].size();
        memset(check,0,sizeof(check));
        dfs(image,sr,sc);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(check[i][j]) image[i][j] = newColor;
            }
        }
        image[sr][sc] = newColor;
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc){
        if(sr > 0){
            if(image[sr][sc] == image[sr - 1][sc] and !check[sr - 1][sc]){
                check[sr - 1][sc] = 1;
                dfs(image,sr-1,sc);
            }
        }
        if(sr < n - 1){
            if(image[sr][sc] == image[sr + 1][sc] and !check[sr + 1][sc]){
                check[sr + 1][sc] = 1;
                dfs(image,sr+1,sc);
            }
        }
        if(sc > 0){
            if(image[sr][sc] == image[sr][sc - 1] and !check[sr][sc - 1]){
                check[sr][sc - 1] = 1;
                dfs(image,sr,sc-1);
            }
        }
        if(sc < m - 1){
            if(image[sr][sc] == image[sr][sc + 1] and !check[sr][sc + 1]){
                check[sr][sc + 1] = 1;
                dfs(image,sr,sc+1);
            }
        }
    }
};
