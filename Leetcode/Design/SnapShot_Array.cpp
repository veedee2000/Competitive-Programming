class SnapshotArray {
    
    int totalSnaps;
    unordered_map<int,vector<pair<int,int>>>values;
    
    int lowerBound(int snap_id,vector<pair<int,int>>& vec){
        int l = 0, r = vec.size() - 1, m, ans;
        while(l <= r) {
            m = l + (r - l) / 2;
            if(vec[m].first <= snap_id) ans = vec[m].second, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    
public:
    
    SnapshotArray(int length) {
        totalSnaps = 0;
        for(int i = 0;i < length;i++) values[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        int sz = values[index].size();
        if(values[index][sz - 1].first == totalSnaps) {
            values[index][sz - 1].second = val;
        }
        else values[index].push_back({totalSnaps,val});
    }
    
    int snap() {
        return totalSnaps++;
    }
    
    int get(int index, int snap_id) {
        return lowerBound(snap_id,values[index]);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
