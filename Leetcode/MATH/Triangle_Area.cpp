class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = INT_MIN;
        for(int i = 0;i < points.size();i++){
            for(int j = i + 1;j < points.size();j++){
                double a = f(i,j,points);
                for(int k = j + 1;k < points.size();k++){
                    double b = f(j,k,points),c = f(i,k,points);
                    double s = (a + b + c) / 2;
                    double val = s * (s - a) * (s - b) * (s - c);
                    ans = max(ans,val);
                }
            }
        }
        return sqrt(ans);
    }
    
    double f(int i,int j,vector<vector<int>>& points){
        double size = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        return sqrt(size);
    }
};
