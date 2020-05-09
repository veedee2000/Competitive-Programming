https://leetcode.com/discuss/interview-question/357345/


#include <bits/stdc++.h>
using namespace std;

vector<string>ans;

void f(string& s,int index,int val,int totalVal){
    
    if(index == 10){
        if(totalVal == 100) ans.push_back(s);
        return;
    }
    
    s.push_back((char) index + '0');
    f(s,index + 1,val * 10 + index,totalVal - val + val * 10 + (val < 0 ? -index : index));
    s.pop_back();
    
    if(index > 1){
        s.push_back('+');
        s.push_back((char) index + '0');
        f(s,index + 1,index,totalVal + index);
        s.pop_back();
        s.pop_back();
    }
    
    s.push_back('-');
    s.push_back((char) index + '0');
    f(s,index + 1,-index,totalVal - index);
    s.pop_back();
    s.pop_back();
}

int main() {
    
    string s = "";
    
    f(s,1,0,0);
    
    // vector<string>ans1;
    
    // while(cin>>s){
    //     ans1.push_back(s);
    // }
    
    sort(ans.begin(),ans.end());
    // sort(ans1.begin(),ans1.end());
    // cout<<(ans == ans1);
    
    for(auto x:ans) cout<<ans;
    
	return 0;
}
