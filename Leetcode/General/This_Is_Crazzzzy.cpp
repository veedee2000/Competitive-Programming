class Solution {
public:
    queue<pair<int,int>>q;
    vector<vector<int>>ans;
    bool b[110][110];
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        ans.resize(R, vector<int>(0));
        ans[0].push_back(r0);
        ans[0].push_back(c0);
        memset(b,0,sizeof(b));
        bfs(R,C,r0,c0);
        cout<<ans[1][0]<<" "<<ans[1][1];
        return ans;
    }
    
    void bfs(int R, int C, int r0, int c0){
        q.push({r0,c0});
        int i = 1;
        int count = R*C - 1;
        while(count--){
            int curr_x = q.front().first, curr_y = q.front().second;
            q.pop();
            b[curr_x][curr_y] = 1;
            if(curr_x > 0){
                if(!b[curr_x - 1][curr_y]){
                    q.push({curr_x - 1,curr_y});
                    ans[i].push_back(curr_x - 1);
                    ans[i].push_back(curr_y);
                    ++i;
                }
            }
            if(curr_x < R - 1){
                if(!b[curr_x + 1][curr_y]){
                    q.push({curr_x + 1,curr_y});
                    ans[i].push_back(curr_x + 1);
                    ans[i].push_back(curr_y);
                    ++i;
                }
            }
            if(curr_y > 0){
                if(!b[curr_x][curr_y - 1]){
                    q.push({curr_x,curr_y - 1});
                    ans[i].push_back(curr_x);
                    ans[i].push_back(curr_y - 1);
                    ++i;
                }
            }
            if(curr_y < C - 1){
                if(!b[curr_x][curr_y + 1]){
                    q.push({curr_x,curr_y + 1});
                    ans[i].push_back(curr_x);
                    ans[i].push_back(curr_y + 1);
                    ++i;
                }
            }
            cout<<q.size();
        }
    }
};
