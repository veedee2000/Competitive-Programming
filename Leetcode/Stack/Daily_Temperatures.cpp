class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ans(T.size(),0);
        stack<pair<int,int>>s;
        int i = 0;
        for(auto x:T){
            if(s.empty()) s.push({x,i++});
            else{
                if(s.top().first >= x) s.push({x,i++});
                else{
                    while(!s.empty() and s.top().first < x){
                        ans[s.top().second] = (i - s.top().second);
                        s.pop();
                    }
                    s.push({x,i++});
                }
            }
        }
        return ans;
    }
};
