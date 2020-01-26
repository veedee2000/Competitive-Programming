#include <bits/stdc++.h>
using namespace std;

void rearrange(long long int a[],int n){
    int min_in = 0,max_in = n - 1;
    long long int max_val = a[n - 1] + 1;
    for(int i = 0;i < n;i++){
        if(i % 2 == 0){
            a[i] += (a[max_in] % max_val) * max_val;
            max_in--;
        }
        else{
            a[i] += (a[min_in] % max_val) * max_val;
            min_in++;
        }
    }
    for(int i = 0;i < n;i++) a[i] /= max_val;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int a[n + 10];
	    for(int i = 0;i < n;i++){
	        cin>>a[i];
	    }
	    rearrange(a,n);
	    for(int i = 0;i < n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
