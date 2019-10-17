class Solution {
public:
    
    vector<bool> camelMatch(vector<string>& a, string pattern) {
        vector<bool>ans;
        int capitals_pattern = 0;
        for(int i=0;i<pattern.size();i++){
            
            int current = pattern[i] - 'A';
            if(current >= 0 and current <= 25) ++capitals_pattern;
        }
        for(auto x:a){
            
            int capitals = 0;
            for(int i=0;i<x.size();i++){
            
                int current = x[i] - 'A';
                if(current >= 0 and current <= 25) ++capitals;
            }
            
            bool check = false;
            int p_index = 0,sz=0;
            for(int i=0;i<x.size();i++){
                if(pattern[p_index] == x[i]) { sz++; p_index++; }
                if(sz == pattern.size() and capitals == capitals_pattern) { check = true; break; }
            }
            ans.push_back(check);
        }
        return ans;
    }
};
