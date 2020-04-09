class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double avg = 0;
        int ans = 0;
        for(int i = 0;i < k;i++) avg += arr[i];
        avg /= k;
        for(int i = k;i <= arr.size();i++){
            if(avg >= threshold) ans++;
            if(i < arr.size())avg += (double) (arr[i] - arr[i - k]) / k;
        }
        return ans;
    }
};
