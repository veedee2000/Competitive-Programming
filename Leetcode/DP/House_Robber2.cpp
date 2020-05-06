#include <bits/stdc++.h>
using namespace std;

vector<int>dp; // Store the maximum possible at each index

int f(int i,vector<int>& subItems){
    if(i >= subItems.size()) return 0; // When i exceeds the index of the last element simply return 0
    
    if(dp[i] != -1) return dp[i]; // If the value has already been calculated, directly return it from the dp array
    
    /*
        The next states are : don't take this element and go to i + 1 th state 
        else, take this element and go to i + 2 th state
    */ 
    
    return dp[i] = max(f(i + 1,subItems) , subItems[i] + f(i + 2,subItems));
        
}

int main() {
    
    vector<int> items = {2,3,2};
    
    vector<int>subItems = items;
    subItems.pop_back();           // subItems contains elements from 0 to items.size() - 2
    
    dp.resize(subItems.size(),-1); // Initializing all the values with -1
    
    int max1 = f(0,subItems);       // Calculating maximum possible sum for first scenario
    
    subItems = items;
    subItems.erase(subItems.begin());     // subItems contains elements from 1 to items.size() - 1
        
    dp.clear();
    dp.resize(subItems.size(),-1);         // Re-initializing all values with -1
    
    int max2 = f(0,subItems);  // Calculating maximum possible sum for second scenario
    
    cout << max(max1 , max2) << endl; // Printing the maximum between them
    
	return 0;
}
