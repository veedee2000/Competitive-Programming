// https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/good-binary-string/problem

int minimumMoves(string s, int d) {
    vector<int>v;
    int ans = 0;
    v.push_back(-1);
    for(int i = 0;i < (int) s.size();i++) if(s[i] == '1') v.push_back(i);
    v.push_back((int)s.size());
    for(auto x:v) cout<<x<<" ";
    for(int i = 1;i < (int) v.size();i++){
        ans += (v[i] - v[i - 1] - 1) / d;
    }
    return ans;
}
