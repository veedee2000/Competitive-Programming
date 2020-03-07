class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        queue<vector<string>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        q.push({beginWord});
        bool c = 0;
        while(!q.empty()){
            int sz = q.size();
            for(string x:vis) st.erase(x);
            vis.clear();
            while(sz--){
                vector<string>list = q.front();
                q.pop();
                string lastWord = list.back();
                vis.insert(lastWord);
                if(lastWord == endWord) {ans.push_back(list); c = 1;}
                if(c) continue;
                for(int i = 0;i < lastWord.size();i++){
                    string buff = lastWord;
                    for(auto c = 'a'; c <= 'z';c++){
                        buff[i] = c;
                        if(st.count(buff)){
                            list.push_back(buff);
                            vis.insert(buff);
                            q.push(list);
                            list.pop_back();
                        }
                    }
                }
            }
            if(c) return ans;
        }
        return {};
    }
};
