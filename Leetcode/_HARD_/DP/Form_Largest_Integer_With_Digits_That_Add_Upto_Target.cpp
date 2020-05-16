class Solution {
public:
    vector<string>dp;
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(target + 1,"#");
        return f(target,cost);
    }
    
    string f(int target,vector<int>& cost){
        if(target == 0) return "";
        if(dp[target] != "#") return dp[target];
        string ans = "0",val = "";
        for(int i = 1;i <= 9;i++){
            if(cost[i - 1] <= target){
                val.push_back(i + '0');
                string s = f(target - cost[i - 1],cost);
                if(s == "0") val = "0";
                else val += s;
            }
            ans = (comp(ans,val) ? ans : val);
            val = "";
        }
        return dp[target] = ans;
    }
    
    bool comp(string& a,string& b){
        if(a.size() != b.size()) return (a.size() > b.size());
        for(int i = 0;i < a.size();i++){
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return 1;
    }
};
