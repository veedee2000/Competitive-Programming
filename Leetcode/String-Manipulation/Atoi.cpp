class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int i=0;
        while(i<str.length() && str[i]==' ') i++;
        if(i==str.length()) return 0;
        int sign = (str[i]=='-')?-1:1;
        if(str[i]=='-' || str[i]=='+') i++;
        while(i<str.length() && str[i]>='0' && str[i]<='9'){
            res = res*10 + sign*(str[i]-'0');
            if(res<INT_MIN) return INT_MIN;
            else if(res>INT_MAX) return INT_MAX;
            i++;
        }
	    return res;
    }
};
