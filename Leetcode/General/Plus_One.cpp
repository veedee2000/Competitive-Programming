class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool c = 1;
        for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] < 9) { digits[i]++; c = 0; break; }
            else digits[i] = 0;
        }
        if(c) digits.insert(digits.begin(),1);
        return digits;
    }
};
