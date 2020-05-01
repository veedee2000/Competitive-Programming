// https://leetcode.com/discuss/interview-question/396769/

#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	for(int i = 0;i < 5;i++){
	    if(s[i] == '?'){
	        if(i == 0){
	            if(s[i + 1] == '?') {
	                s[i] = '2',s[i + 1] = '3';
	            }
	            else{
	                if(s[i + 1] < '4') s[i] = '2';
	                else s[i] = '1';
	            }
	        }
	        else if(i == 1){
	            if(s[i - 1] < '2') s[i] = '9';
	            else s[i] = '3';
	        }
	        else if(i == 3){
	            if(s[i + 1] == '?') {
	                s[i] = '5',s[i + 1] = '9';
	            }
	            else{
	                s[i] = '5';
	            }
	        }
	        else s[i] = '9';
	    }
	}
	for(auto x:s) cout<<x;
	return 0;
}
