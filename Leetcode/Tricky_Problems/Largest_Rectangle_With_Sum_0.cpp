#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>>matrix(m,vector<int>(n));
    
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> matrix[i][j];
    
    vector<int>currArray(m,0);
    int ansL, ansR, ansT, ansB;
    
    for(int L = 0;L < n;L++){
        for(auto &x:currArray) x = 0;
        for(int R = L;R < n;R++){
            for(int i = 0;i < m;i++) currArray[i] += matrix[i][R];
            int prefix = 0;
            unordered_map<int,int>mp;
            mp[0] = -1;
            for(int i = 0;i < m;i++){
                prefix += currArray[i];
                if(mp.count(prefix) and (R - L) * (i - mp[prefix]) > (ansR - ansL) * (ansB - ansT)) ansL = L, ansR = R, ansT = mp[prefix] + 1, ansB = i;
                else if(!mp.count(prefix)) mp[prefix] = i;
            }
        }
    }
    
    for(int i = ansT;i <= ansB;i++){
        for(int j = ansL;j <= ansR;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
	return 0;
}
