class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>>vec;
        for(int i = 0;i < groupSizes.size();i++){
            vec.push_back({groupSizes[i],i});
        }
        sort(vec.begin(),vec.end(),comp);
        vector<vector<int>>v(groupSizes.size(),vector<int>(0));
        int sz = 0;
        int count = 0,current = 0;
        for(int i = 0;i < groupSizes.size();i++){
            count++;
            if(i == 0) v[0].push_back(vec[i].second);
            else{
                if(vec[i].first == vec[i - 1].first){
                    if(count <= vec[i].first) v[current].push_back(vec[i].second);
                    else{
                        current++,count = 1;
                        v[current].push_back(vec[i].second);
                    }
                }
                else{
                    count = 1,current++;
                    v[current].push_back(vec[i].second);
                }
            }
        }
        v.resize(current + 1);
        return v;
    }
    
    bool static comp(pair<int,int>a,pair<int,int>b){
        return a.first < b.first;
    }
};
