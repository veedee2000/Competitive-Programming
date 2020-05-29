// https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/optimal-path-1

struct comp{
    bool operator()(vector<int>& a,vector<int>& b){
        return a[2] > b[2];
    }
};

int getMinEffort(vector<vector<int>> C) {
    priority_queue<vector<int>,vector<vector<int>>,comp>pq;
    int m = C.size(), n = C[0].size();
    vector<vector<long>>dist(m,vector<long>(n,LONG_MAX));
    pq.push({0,0,0});
    dist[0][0] = 0;
    vector<int>dr = {0,0,-1,1}, dc = {-1,1,0,0};
    while(!pq.empty()){
        vector<int>curr = pq.top();
        pq.pop();
        int i = curr[0], j = curr[1], val = curr[2];
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc], y = j + dc[rc];
            if(x >= 0 and y >= 0 and x < m and y < n and dist[x][y] > max(val, abs(C[i][j] - C[x][y]))){
                dist[x][y] = max(val, abs(C[i][j] - C[x][y]));
                pq.push({x,y,(int) dist[x][y]});
            }
        }
    }
    return dist[m - 1][n - 1];
}
