class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = 1,c = 0;
        while(i <= num1.size() or i <= num2.size()){
            int total = (i <= num1.size() ? num1[num1.size() - i] - '0' : 0) + (i <= num2.size() ? num2[num2.size() - i] - '0' : 0) + c;
            ans = to_string(total % 10) + ans;
            c = total / 10;
            i++;
        }
        if(c) ans = to_string(c) + ans;
        return ans;
    }
};
