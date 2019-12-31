class Solution { 
    map<int,bool>mymap;
bool dfs(int total,int maxint,vector<bool>&visited,int mask){
    if(mymap.count(mask))
        return mymap[mask];
    
    for(int i=1;i<=maxint;i++){
        if(visited[i]==true) continue;
        if(i>=total) return mymap[mask] = 1;
        visited[i]=true;
        if(dfs(total-i,maxint,visited,mask|1<<(i)) == 0){
            visited[i] = 0;
            return mymap[mask] = 1;
        }
        visited[i] = 0;
    }
    return mymap[mask] = 0;
}
    
public:
    bool canIWin(int maxint, int total) {
        
        if(total>((maxint)*(maxint+1))/2) return 0;
        
        vector<bool>visited(maxint+1,0);
        return dfs(total,maxint,visited,0);
    }
};
