class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        for(int i = 0;i < n;i++){
            if(n % 2 and i == n / 2) continue;
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            if(n % 2 and i == n / 2) continue;
            if(palindrome[i] != 'z'){
                palindrome[i]++;
                return palindrome;
            }
        }
        return "";
    }
};
