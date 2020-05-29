// https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/arrange-students/submissions/code/1323904771

bool f(int l,int r,bool gen,vector<int>& a,vector<int>& b){
    if(l == (int) a.size() or r == (int) a.size()) return 1;
    cout<<l<<" "<<r<<" "<<gen<<endl;
    if(!gen){
        if(b[r] <= a[l]) return f(l,r + 1,!gen,a,b);
        else return 0;
    }
    else{
        if(a[l] <= b[r]) return f(l + 1,r,!gen,a,b);
        else return 0;
    }
}

string returnFunc(bool c){
    return c ? "YES" : "NO";
}

string arrangeStudents(vector<int> a, vector<int> b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a[0] == b[0]) return returnFunc(f(1,0,0,a,b) or f(0,1,1,a,b));
    else if(a[0] < b[0]) return returnFunc(f(1,0,0,a,b));
    else return returnFunc(f(0,1,1,a,b));
}
