#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	
	// This sets all the bits from MSB
	
	n++;
	
	cout << (n >> 1);
	
	
	return 0;
}
