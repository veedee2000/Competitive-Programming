class Solution {
    
    int distance(vector<int>& a, vector<int>& b){
        return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size(), l = 0, r = n - 1, m;
        while(1){
            m = l + (r - l) / 2;
            swap(points[m], points[r]);
            int partition = l;
            for(int index = l;index < r;index++){
                if(distance(points[r], points[index])) swap(points[index], points[partition++]);
            }
            swap(points[partition], points[r]);
            if(partition == k - 1) break;
            else if(partition < k - 1) l = partition + 1;
            else r = partition - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
