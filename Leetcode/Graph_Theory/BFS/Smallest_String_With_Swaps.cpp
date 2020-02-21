class Solution {
public:
    int kSimilarity(string A, string B) {
        int ans = 0;
        unordered_map<string,bool>mp;
        queue<pair<string,int>>q;
        q.push({A,0});
        mp[A] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front().first;
                int id = q.front().second;
                q.pop();
                if(curr == B) return ans;
                while(id < B.size() and curr[id] == B[id]) ++id;
                for(int i = id + 1;i < B.size();i++){
                    if(curr[i] == B[id]){
                        string buff = curr;
                        swap(buff[i],buff[id]);
                        if(!mp.count(buff)) mp[buff] = 1,q.push({buff,id});
                    }
                }
            }
            ++ans;
        }
        return 0;
    }
};
