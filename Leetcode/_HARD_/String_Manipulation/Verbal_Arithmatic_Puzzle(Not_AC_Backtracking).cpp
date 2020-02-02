#include <bits/stdc++.h>
using namespace std;

    set<char>st;
    vector<char>s;
    
    
    bool f(int x,int maxgo,vector<int>v,unordered_map<int,bool>mp,vector<string>& words, string result){
        if(x == 0){
            // for(auto it : v) cout<<it<<" ";
            // cout<<endl;
            unordered_map<char,int>m;
            int i = 0;
            for(auto c:s){
                m[c] = v[i++];
            }
            int ans = 0;
            for(string &word : words){
                string im = "";
                for(auto c:word) im.push_back(m[c] + '0');
                // cout<<stoi(im)<<" ";
                ans += stoi(im);
            }
            
            int ansmatch = 0;
            string im = "";
            for(auto c:result) im.push_back(m[c] + '0');
            // cout<<stoi(im)<<" ";
            ansmatch = stoi(im);
            return (ans == ansmatch);
        }
        bool ans = 0;
        for(int i = (maxgo > 0 ? 1 : 0);i < 10;i++){
            if(mp[i] == 1){
                mp[i] = 0;
                v.push_back(i);
                ans |= f(x - 1,maxgo - 1,v,mp,words,result);
                v.pop_back();
                mp[i] = 1;
            }
        }
        return ans;
    }
    
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char,int>sub;
        for(auto word:words){
            if(!sub.count(word[0])) s.push_back(word[0]);
            sub[word[0]] = 1;
            for(auto c:word) if(!sub.count(c)) st.insert(c);
        }
        if(!sub.count(result[0])) s.push_back(result[0]);
        sub[result[0]] = 1;
        for(auto c:result){
            if(!sub.count(c)) st.insert(c);
        }
        
        
        int mx = s.size();
        for(auto x:st) if(!sub.count(x)) s.push_back(x);
        
        // cout<<mx<<" "<<s.size()<<endl;
        // for(auto x:s) cout<<x<<" ";
        
        unordered_map<int,bool>mp;
        for(int i = 0;i < 10;i++) mp[i] = 1;
        return f(s.size(),mx,{},mp,words,result);
    }
    

int main() {
	vector<string>p = {"SIX","SEVEN","SEVEN"};
	string p1 = "TWENTY";
	cout<<isSolvable(p,p1);
	return 0;
}
