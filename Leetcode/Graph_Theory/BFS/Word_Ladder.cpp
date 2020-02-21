class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        vector<string>buff;
        for(int i = 0;i < wordList.size();i++){
            if(wordList[i] != beginWord) buff.push_back(wordList[i]);
        }
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return ans;
                buff = {};
                for(auto x:wordList){
                    int count = 0;
                    for(int i = 0;i < x.size();i++){
                        if(curr[i] != x[i]) count++;
                        if(count > 1) break;
                    }
                    if(count == 1) q.push(x);
                    else buff.push_back(x);
                }
                wordList = buff;
            }
            ++ans;
        }
        return 0;
    }
};
