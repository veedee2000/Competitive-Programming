class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        vector<string>ans;
        vector<pair<int,string>>arr;
        for(auto x:words) mp[x]++;
        
        for(auto x:mp) arr.push_back({x.second,x.first});
        
        sort(arr.begin(),arr.end(),compare);
        for(auto x:arr){
            if(k--){
                ans.push_back(x.second);
            }
            else break;
        }
        return ans;
    }
    
    
    bool static compare(pair<int,string>a, pair<int,string>b){
        if(a.first > b.first) return true;
        else if(a.first == b.first) return a.second < b.second;
        else return false;
    }
};

