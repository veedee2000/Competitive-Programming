class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>st;
        for(auto x:words){
            string s="";
            for(int i=0;i<x.size();i++){
                s+=arr[x[i] - 'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};
