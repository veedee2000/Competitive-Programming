class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<vector<int>>v(10, vector<int>(0));
        for(auto x:nums){
            string s = to_string(x);
            v[s[0] - '0'].push_back(x);
        }
        for(int i = 0; i < 10; i++){
            sort(v[i].begin(),v[i].end(),compare);
        }
        for(auto x:v[1]) cout<<x<<" ";
        string ans = "";
        for(int i = 9;i >= 0; i--){
            for(auto x:v[i]){
                ans += to_string(x);
            }
        }
        
        string check = "0";
        int c = 100;
        while(c--){
            if(check == ans) return "0";
            check += "0";
        }
        
        return ans;
    }
    
    bool static compare(int a1, int a2){
        string s1 = "";
        s1 += to_string(a1);
        string s2 = "";
        s2 += to_string(a2);
        if(s1.size() == s2.size()) return (a1 > a2);
        else if(s1.size() > s2.size()){
            while(s2.size() < s1.size()){
                s2 += max(s2[0], s2[s2.size() - 1]);
            }
            return (s1 > s2);
        }
        else{
            while(s1.size() < s2.size()){
                s1 += max(s1[0], s1[s1.size() - 1]);
            }
            return (s1 > s2);
        }
    }
    
};
