class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        vector<int>heights(matrix[0].size(),0);
        int ans = 0;
        for(int i = 0;i < matrix.size();i++){
            stack<int>height,position;
            for(int j = 0;j < matrix[0].size();j++){
                heights[j] = (i == 0) ? matrix[i][j] - '0' : ((matrix[i][j] == '1') ? heights[j] + 1 : 0);
            }
            
            int pos = 0;
            while(pos < heights.size()){
                if(height.empty() or height.top() < heights[pos]) height.push(heights[pos]),position.push(pos);
                if(height.top() == heights[pos]) { pos++; continue; }
                else{
                    int positionVal = 0;
                    while(!height.empty() and height.top() > heights[pos]){
                        ans = max(ans,(pos - position.top()) * height.top());
                        positionVal = position.top();
                        height.pop();
                        position.pop();
                    }
                    position.push(positionVal);
                    height.push(heights[pos]);
                }
                pos++;
            }
            while(!height.empty()){
                ans = max(ans,(pos - position.top()) * height.top());
                height.pop();
                position.pop();
            }
        }
        
        return ans;
    }
};
