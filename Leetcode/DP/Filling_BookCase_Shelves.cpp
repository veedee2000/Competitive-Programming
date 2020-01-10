const int INF = 10000000;

class Solution {
public:
    vector<int>dp;
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        dp.resize(books.size(), -1);
        return f(0,books,shelf_width);
    }
    
    int f(int startIndex,vector<vector<int>>& books,int shelf_width){
        if(startIndex >= books.size()) return 0;
        if(dp[startIndex] != -1) return dp[startIndex];
        int otherShelvesHeight = 0;
        int currShelfHeight = 0;
        int minShelfHeight = INF;
        int widthRem = shelf_width;
        for(int i = startIndex;i < books.size() and widthRem >= books[i][0];i++){
            widthRem -= books[i][0];
            currShelfHeight = max(currShelfHeight,books[i][1]);
            otherShelvesHeight = f(i + 1,books,shelf_width);
            minShelfHeight = min(minShelfHeight,otherShelvesHeight + currShelfHeight);
        }
        return dp[startIndex] = minShelfHeight;
    }
    
};
