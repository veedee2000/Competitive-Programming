class Solution {
public:
    bool check[10000];
    int ans = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(check,0,sizeof(check));
        dfs(0, rooms);
        return (ans == rooms.size());
    }
    
    void dfs(int i, vector<vector<int>>& rooms){
        check[i] = 1;
        ++ans;
        for(int j = 0;j < rooms[i].size();j++){
            if(!check[rooms[i][j]]) dfs(rooms[i][j], rooms);
        }
    }
};
