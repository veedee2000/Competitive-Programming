const int MAX = 10000000;
class Solution{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,MAX));
        
        for(int i = 0;i < n;i++) dist[i][i] = 0;
        for(auto x:edges) dist[x[0]][x[1]] = x[2] = dist[x[1]][x[0]] = x[2];
        
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int ans,val,minVal = INT_MAX;
        for(int i = 0;i < n;i++){
            val = 0;
            for(auto x:dist[i]){
                if(x <= distanceThreshold) val++;
            }
            if(val <= minVal) ans = i,minVal = val;
        }
        return ans;
    }
};
