class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool>mp;
        for(auto x:deadends) mp[x] = 1;
        queue<string>q;
        q.push("0000");
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i < sz;i++){
                string curr = q.front();
                q.pop();
                if(mp.count(curr)) continue;
                if(curr == target) return ans;
                mp[curr] = 1;
                string s1;
                for(int in = 0;in < 4;in++){
                    s1 = curr;
                    if(curr[in] != '9') s1[in]++;
                    else s1[in] = '0';
                    if(!mp.count(s1)) q.push(s1);
                }
                for(int in = 0;in < 4;in++){
                    s1 = curr;
                    if(curr[in] != '0') s1[in]--;
                    else s1[in] = '9';
                    if(!mp.count(s1)) q.push(s1);
                }
            }
            ++ans;
        }
        return -1;
    }
};
