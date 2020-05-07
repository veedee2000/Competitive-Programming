#include <bits/stdc++.h>
using namespace std;

int main() {
    
	vector<int> piles = {3, 6, 7, 11};   // Piles with items
	
    int T = 8;   // Number of hours
    
    int maxVal = piles[0];   // Initializing maximum value 
    
    for(auto x:piles) maxVal = max(maxVal,x);  // Finding maximum value in piles
    
    int l = 1, r = maxVal, m;  
    int ans, req;
    
    while(l <= r){   // Binary Search on the answer
        
        m = l + (r - l) / 2; // m is the mid-point of the array 
        
        req = 0;
        
        for(auto x:piles) req += x / m + (x % m > 0);  // Finding the total number of hours needed to completely consume all piles
        
        if(req > T) l = m + 1;  // If the required number of hours is more than T, it means we need to consume more bananas per hour
        
        else ans = m,r = m - 1;  // If the required number of hours is less than or equal to T, it means this is a possible answer and we go to check if any smaller value exists
    }
    
    cout << ans << endl;
    
	return 0;
}
