class Solution {
public:
    string removeDuplicates(string S, int k) {
        stack<pair<char,int>>s;
        string ans;
        s.push({S[0],1});
        for(int i = 1;i < S.size();i++){
            if(!s.empty() and S[i] == s.top().first){
                if(s.top().second + 1 < k) s.push({S[i],s.top().second + 1});
                else if(s.top().second + 1 == k){
                    int p = k;
                    while(--p) s.pop();
                }
            }
            else s.push({S[i],1});
        }
        while(!s.empty()){
            ans.push_back(s.top().first);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
