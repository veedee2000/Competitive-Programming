class Solution {
public:
    string longestWord(vector<string>& v) {
        set<string>s,st;
        for(auto x:v) s.insert(x);
        for(auto x:v){
            string val = "";
            bool c = 1;
            for(int i=0;i<x.size();i++){
                val+=x[i];
                if(s.count(val) == 0) {c = 0; break;}
            }
            if(c) st.insert(x);
        }
        int mx = 0;
        for(auto x:st){
            mx = max(mx, int(x.size()) );
        }
        // cout<<mx;
        for(auto x:st) cout<<x<<" ";

        for(auto x:st){
            if(int(x.size()) == mx) return x;
        }
        
        return "";
    }
};
