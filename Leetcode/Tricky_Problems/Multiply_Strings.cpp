class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans,val,zeros = "";
        int carry = 0, value;
        unordered_map<char,string>mp;
        for(auto dig:num1){
            carry = 0;
            if(!mp.count(dig)){
                for(auto x:num2){
                    value = (x - '0') * (dig - '0') + carry;
                    val.push_back((value % 10) + '0');
                    carry = value / 10;
                }
                if(carry) val.push_back(carry + '0'), carry = 0;
                mp[dig] = val;
            }
            else val = mp[dig];
            val = zeros + val;
            int i;
            for(i = 0;i < min(ans.size(),val.size());i++){
                value = ((val[i] - '0') + (ans[i] - '0') + carry);
                ans[i] = (value % 10) + '0';
                carry = value / 10;
            }
            while(i < ans.size()){
                value = (ans[i] - '0') + carry;
                ans[i] = (value % 10) + '0';
                carry = value / 10;
                i++;
            }
            while(i < val.size()){
                value = (val[i] - '0') + carry;
                ans.push_back((value % 10) + '0');
                carry = value / 10;
                i++;
            }
            if(carry) ans.push_back(carry + '0'), carry = 0;
            zeros += "0";
            val.clear();
        }
        reverse(ans.begin(),ans.end());
        string check = ans;
        sort(check.begin(),check.end(),greater<int>());
        if(check.size() and check[0] == '0') return "0";
        return ans;
    }
};
