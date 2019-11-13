class Solution {
public:
    int balancedString(string s) {
        unordered_map<int,unordered_map<char,int>>mp;
        char arr[] = {'Q','W','E','R'};
        
        for(int i = 0;i < 4;i++){       // Initializing with 0 or 1
            mp[0][arr[i]] = (s[0] == arr[i] ? 1 : 0);
        }
        
        for(int i = 1;i < s.size();i++){  // Creating the map
            for(int j = 0;j < 4;j++){
                mp[i][arr[j]] = mp[i - 1][arr[j]];
            }
            mp[i][s[i]]++;
        }
        int count[4];
        for(int i = 0;i < 4;i++){
            count[i] = max(int (mp[s.size() - 1][arr[i]] - s.size() / 4), 0);
        }
        bool c = 1;
        for(int i = 0;i < 4;i++) c &= (count[i] == 0);  // Checks if string is already balanced
        if(c) return 0;
        int l = 0,r = 0;
        int ans = INT_MAX;
        while(r < s.size()){
            c = 1;
            for(int i = 0;i < 4;i++){
                c &= (count[i] <= mp[r][arr[i]] - (l > 0 ? mp[l - 1][arr[i]] : 0));
            }
            if(c){   // Checks if this substring is balanced or not
                ans = min(ans,r - l + 1);
                ++l;
            }
            else ++r;
        }
        return ans;
    }
};
