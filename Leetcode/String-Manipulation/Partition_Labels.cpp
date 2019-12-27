class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>ans;
        unordered_map<char,int>last;
        for(int i = 0;i < S.size();i++){
            last[S[i]] = i;
        }
        int beg = 0,end = 0;
        for(int i = 0;i < S.size();i++){
            end = max(end,last[S[i]]);
            if(end == i){
                ans.push_back(end - beg + 1);
                beg = i + 1;
            }
        }
        return ans;
    }
};
