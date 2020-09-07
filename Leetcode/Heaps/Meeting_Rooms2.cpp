int minMeetingRooms(vector<Interval> &intervals) {
    vector<int>start, end;
    for(auto meet:intervals) start.push_back(meet.start), end.push_back(meet.end);
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0, j = 0, count = 0, ans = 0;
    while(i < (int)intervals.size()){
        if(start[i] < end[j]) count++, i++;
        else count--, j++;
        ans = max(ans, count);
    }
    return ans;
}
