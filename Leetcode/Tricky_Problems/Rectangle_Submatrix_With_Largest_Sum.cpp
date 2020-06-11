#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>>matrix(m,vector<int>(n));
    
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> matrix[i][j];
    
    vector<int>currArray(m,0);
    int ansL, ansR, ansT, ansB, maxVal = 0;
    
    for(int L = 0;L < n;L++){
        for(auto &x:currArray) x = 0;
        for(int R = L;R < n;R++){
            for(int i = 0;i < m;i++) currArray[i] += matrix[i][R];
            int currSum = 0, begin = 0;
            for(int i = 0;i < m;i++){
                currSum += currArray[i];
                if(currSum < 0) { currSum = 0; begin = i + 1; continue; }
                if(currSum > maxVal) {
                    ansL = L, ansR = R, ansT = begin, ansB = i, maxVal = currSum;
                }
            }
        }
    }
    
    for(int i = ansL;i <= ansR;i++){
        for(int j = ansT;j <= ansB;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
	return 0;
}
