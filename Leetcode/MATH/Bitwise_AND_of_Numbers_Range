class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        string s1,s2;
        for(int i = 0;i < 32;i++){
            if((1 << i) > m) break;
            if((1 << i) & m) s1.insert(0,1,'1');
            else s1.insert(0,1,'0');
        }
        for(int i = 0;i < 32;i++){
            if((1 << i) > n) break;
            if((1 << i) & n) s2.insert(0,1,'1');
            else s2.insert(0,1,'0');
        }
        if(s1.size() != s2.size()) return 0;
        int index = 0,sz = s1.size(),ans = 0;
        while(index < sz and s1[index] == s2[index]){
            if(s1[index] == '1') ans |= (1 << (sz - index - 1));
            index++;
        }
        return ans;
    }
};
