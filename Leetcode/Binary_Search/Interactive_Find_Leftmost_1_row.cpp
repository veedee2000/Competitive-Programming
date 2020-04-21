/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &matrix) {
        vector<int>dim = matrix.dimensions();
        int m = dim[0],n = dim[1],ans = INT_MAX;
        
        for(int i = 0;i < m;i++){
            int l = 0,r = n - 1,mid,val = -1;
            while(l <= r){
                mid = l + (r - l) / 2;
                if(matrix.get(i,mid)) val = mid,r = mid - 1;
                else l = mid + 1;
            }
            if(val != -1) ans = min(val,ans);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
