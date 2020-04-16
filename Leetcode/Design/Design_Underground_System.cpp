class UndergroundSystem {
public:
    
    unordered_map<int,pair<string,int>>mp;
    unordered_map<string,unordered_map<string,pair<long long,int>>>val;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string beginStation = mp[id].first;
        int beginTime = mp[id].second;
        int totalTime = t - beginTime;
        totalTime += (val[beginStation].count(stationName)) ? val[beginStation][stationName].first : 0;
        int count = 1;
        count += (val[beginStation].count(stationName)) ? val[beginStation][stationName].second : 0;
        mp.erase(id);
        val[beginStation][stationName] = {totalTime,count};
    }
    
    double getAverageTime(string startStation, string endStation) {
        int totalTime = val[startStation][endStation].first;
        int count = val[startStation][endStation].second;
        return (double) totalTime / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
