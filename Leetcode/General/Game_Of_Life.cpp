class Solution {
public:
    
    // alive -> alive = 1;
    // alive -> dead = 2;
    // dead -> dead = 0;
    // dead -> alive = -1;
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>d = {0,-1,1};
        int m = board.size(),n = board[0].size();
        for(int x = 0;x < m;x++){
            for(int y = 0;y < n;y++){
                int count = 0;
                for(auto r:d){
                    for(auto c:d){
                        if(r == 0 and c == 0) continue;
                        int x1 = x + r,y1 = y + c;
                        if(x1 >= 0 and y1 >= 0 and x1 < m and y1 < n and board[x1][y1] > 0){
                            count++;
                        }
                    }
                }
                if(board[x][y] == 1){
                    if(count < 2 or count > 3) board[x][y] = 2;
                }
                else{
                    if(count == 3) board[x][y] = -1;
                }
            }
        }
        for(auto &vec:board){
            for(auto &element:vec){
                if(element == 0 or element == 2) element = 0;
                else element = 1;
            }
        }
        
    }
};
