class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        int begin=0;
        int end=x;
        while (begin <= end){
            int mid = begin+(end-begin)/2;
            if (mid <= x/mid && (mid+1) > x/(mid+1)) return mid;
            else if ((mid+1) < x/(mid+1)) begin = mid+1;
            else if ((mid+1) == x/(mid+1)) return mid+1;
            else end = mid-1;
        }
        return end;
    }
};
