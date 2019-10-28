class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        while(n) {s = to_string(n) + s; --n;}
        while(--k){
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};
