// https://leetcode.com/discuss/interview-question/553399/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    if(s.size() < 2) return 0;
    vector<int>v1(26,0),v2(26,0);
    int count1 = 0,count2 = 0;
    v1[s[0] - 'a']++,count1++;
    for(int i = 1;i < s.size();i++) if(v2[s[i] - 'a']++ == 0) count2++;
    int ans = 0;
    int i = 1;
    while(count1 <= count2 and i < s.size()){
        if(count1 == count2) ans++;
        if(v1[s[i] - 'a']++ == 0) count1++;
        if(v2[s[i] - 'a']-- == 1) count2--;
        i++;
    }
    cout<<ans<<endl;
	return 0;
}
