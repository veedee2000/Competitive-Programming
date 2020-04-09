class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>position,height;
        int pos = 0,ans = 0;
        while(pos < heights.size()){
            if(height.empty() or height.top() < heights[pos]){
                position.push(pos),height.push(heights[pos]);
            }
            else if(height.top() > heights[pos]){  
                int positionToBePushed;
                while(!height.empty() and height.top() > heights[pos]){
                    ans = max(ans,(pos - position.top()) * height.top());
                    positionToBePushed = position.top();
                    position.pop(),height.pop();
                }
                position.push(positionToBePushed),height.push(heights[pos]);
            }
            pos++;
        }
        while(!position.empty()){
            ans = max(ans,(pos - position.top()) * height.top());
            position.pop(),height.pop();
        }
        return ans;
    }
};
