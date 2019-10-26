class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        for(auto x:emails){
            string s1 = "",s2 = "",s3 = "";
            int i = 0;
            while(x[i] != '@') s1 += x[i],++i;
            while(i < x.size()) s2 += x[i],++i;
            for(i = 0;i < s1.size();i++){
                if(s1[i] == '.') continue;
                else if(s1[i] == '+') break;
                else s3 += s1[i];
            }
            st.insert(s3 + s2);
        }
        return st.size();
    }
};
