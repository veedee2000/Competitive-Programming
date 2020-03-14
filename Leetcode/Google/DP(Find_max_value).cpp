/*

The question asked was given digits 1-9 with each digit associated with a value. Now we have a wall that needs to be painted with those digits and each digit painted requires the value volume, you need to form the largest number possible from this. Given that the sum of the volume of the number is equal to the wall volume.

Input:
1 2 3 4 5 6 7 8 9
1 3 1 5 6 7 2 5 2

wall volume: 5
Output: 33333

*/

#include <bits/stdc++.h>
using namespace std;

vector<int>values;
vector<string>dp;

string maxCal(string a,string b){
	if(a.size() != b.size()) return  (a.size() > b.size()) ? a : b;
	return (a > b) ? a : b;
}

string f(int i){
	if(i == 0) return "";
	if(dp[i] != "0") return dp[i];
	int index = 1;
	while(index < 10){
		if(i >= values[index]) dp[i] = maxCal(dp[i],to_string(index) + f(i - values[index]));
		index++;
	}
	return dp[i];
}

int main() {
	
	values.resize(10); // Value associated with each digit
	for(int i = 1;i < 10;i++) cin>>values[i];
	
	int volume;
	cin>>volume;
	dp.resize(volume + 1,"0");
	cout<<f(volume);
	
	return 0;
}
