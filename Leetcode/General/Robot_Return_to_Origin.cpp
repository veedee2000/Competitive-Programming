class Solution {
public:
    bool judgeCircle(string moves) {
        int v=0,h=0;
        for(int i = 0; i< moves.size();i++){
            if(moves[i] == 'U') v++;
            else if(moves[i] == 'D') v--;
            else if(moves[i] == 'L') h++;
            else h--;
        }
        if(v == 0 and h == 0) return true;
        else return false;
    }
};
