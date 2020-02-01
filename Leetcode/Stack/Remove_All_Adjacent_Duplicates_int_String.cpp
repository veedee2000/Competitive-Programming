class Solution {
public:
    string removeDuplicates(string S) {
        string ans = "";
        stack<char>s;
        s.push(S[0]);
        for(int i = 1;i < S.size();i++){
            if(s.empty() or s.top() != S[i]) s.push(S[i]);
            else{
                int j = i,count = 1;
                while(j < S.size() and s.top() == S[j]) j++,count++;
                i = j - 1;
                if(count%2 == 0) s.pop();
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
