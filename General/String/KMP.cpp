#include<bits/stdc++.h>
using namespace std;

void calKMP(string s,string pattern){
	
	int n = s.size(),m = pattern.size(),i,j;
	
	// Calculating the longest perfix suffix for a given index 
	
	vector<int>lps(m,0);
	i = 1,j = 0;
	while(i < m){
		if(pattern[i] == pattern[j]){
			lps[i++] = ++j;
		}
		else if(j != 0){
			j = lps[j - 1];
		}
		else i++;
	}
	
	// Calculating all occurences of a pattern in the string s
	
	i = 0,j = 0;
	while(i < n){
		if(s[i] == pattern[j]){
			i++,j++;
		}
		
		if(j == m){
			cout<<i - j<<" ";
			j = lps[j - 1];
		}
		
		else if(i < n and s[i] != pattern[j]){
			if(j != 0) j = lps[j - 1];
			else i++;
		}
	}
}

int main(){
	
	string s = "abcdefcde",pattern = "cde";
	calKMP(s,pattern);
	
}
