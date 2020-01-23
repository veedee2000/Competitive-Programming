class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>v;
        int c[256] = {0};
        for(auto x:s) c[(int)x]++;
        for(int i = 0;i < 256;i++){
            if(c[i]) v.push_back({c[i],i});
        }
        sort(v.begin(),v.end(),compare);
        string ans;
        for(auto x:v) ans.append(x.first,x.second);
        return ans;
    }
    
    bool static compare(pair<int,int>a,pair<int,int>b){
        return (a.first > b.first);
    }
};
