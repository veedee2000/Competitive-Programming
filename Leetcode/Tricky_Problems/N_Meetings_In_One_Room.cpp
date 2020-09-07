#include<bits/stdc++.h>
using namespace std;

struct meet{
    int start;
    int end;
    int index;
};

bool comp(meet& a, meet& b){
    return a.end < b.end;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<meet>meeting(n);
        for(int i = 0;i < n;i++) cin >> meeting[i].start, meeting[i].index = i;
        for(int i = 0;i < n;i++) cin >> meeting[i].end;
        sort(meeting.begin(), meeting.end(),comp);
        vector<int>ans = {meeting[0].index};
        int prevEnd = meeting[0].end;
        for(int i = 1;i < n;i++){
            if(prevEnd <= meeting[i].start){
                prevEnd = meeting[i].end;
                ans.push_back(meeting[i].index);
            }
        }
        for(auto x:ans) cout << x + 1 << " ";
        cout << endl;
    }
    
    return 0;
}
