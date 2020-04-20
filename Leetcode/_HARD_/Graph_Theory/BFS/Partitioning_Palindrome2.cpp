class Solution {
public:
    vector<vector<int>>graph;
    string s;
    int minCut(string s) {
        this -> s = s;
        graph.resize(s.size());
        for(int i = 0;i < s.size();i++){
            isPalindrome(i,i);
            isPalindrome(i,i + 1);
        }
        queue<int>q;
        q.push(0);
        int ans = 0;
        vector<bool>visited(s.size(),0);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                if(curr == s.size()) return ans - 1;
                for(auto x:graph[curr]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
    
    void isPalindrome(int start,int end){
        if(start < 0 or end >= s.size()) return;
        if(s[start] == s[end]) graph[start].push_back(end + 1), isPalindrome(start - 1,end + 1);
    }
};
