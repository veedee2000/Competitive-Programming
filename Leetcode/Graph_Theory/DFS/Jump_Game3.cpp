class Solution {
public:
    vector<int>arr;
    vector<bool>b;
    bool ans;
    bool canReach(vector<int>& arr, int start) {
        this -> arr = arr;
        b.resize(arr.size(), 0);
        ans = 0;
        f(start);
        return ans;
    }
    
    void f(int i){
        if(i > arr.size() - 1) return;
        if(b[i]) return;
        if(arr[i] == 0){
            ans = 1;
            return;
        }
        b[i] = 1;
        f(i - arr[i]);
        f(i + arr[i]);
        return;
    }
};
