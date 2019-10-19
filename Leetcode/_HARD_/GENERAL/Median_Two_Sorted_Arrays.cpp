class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int min_val = INT_MIN, max_val = INT_MAX;
        
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size(),n2 = nums2.size();
        int l = 0,r = n1,m;
        while(l <= r){
            
            int m = (l + r)/2;
            int partition_n1 = (l + r)/2;
            int partition_n2 = (n1 + n2 + 1)/2 - partition_n1;
            
            int max_left_n1 = (partition_n1 == 0) ? min_val : nums1[partition_n1 - 1];

            int min_right_n1 = (partition_n1 == n1) ? max_val : nums1[partition_n1];
            
            int max_left_n2 = (partition_n2 == 0) ? min_val : nums2[partition_n2 - 1];
            
            int min_right_n2 = (partition_n2 == n2) ? max_val : nums2[partition_n2];
            
            if(max_left_n1 <= min_right_n2 and max_left_n2 <= min_right_n1){
                if((n1 + n2) % 2 == 0){
                    
                    return ( (double) ((max(max_left_n1, max_left_n2) + min(min_right_n1, min_right_n2))) / 2);
                    
                }
                else{
                    return (double) (max(max_left_n1, max_left_n2));
                    
                }
            }
            
            else if( max_left_n1 > min_right_n2 ){
                r = m - 1;
            }
            
            else{
                l = m + 1;
            }  
        }
        return 0;
    }
};
