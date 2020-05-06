#include<bits/stdc++.h>

using namespace std;

class Stream{
    
    private: 
        vector<int>nums; // Stores all the numbers present currently in the stream
        
        unordered_map<int,unordered_set<int>>mp; // unordered ensure O(1) operation
        
    public:
        
        // Function to insert values inside the stream
        bool insert(int val) {
            
            nums.push_back(val); // Inserting val to the end of array

            int index = nums.size() - 1; // Index at which val was inserted
            mp[val].insert(index); // Inserting the index inside the set mp[val]
            
            return mp[val].size() == 1; // Return True if only one val is present in the stream
        }
        
        // Function to remove values from the stream
        bool remove(int val) {
            
            if(!mp.count(val)) return 0; // If the value is not present in the stream 
            
            int index = *(mp[val].begin()); // Get the value of first element of the mp[val] and store it in variable named index
            int lastIndex = nums.size() - 1; // Last Index of nums
            
            mp[val].erase(index); // Erase the index from mp[val] set
             
            if(index != lastIndex) { // If index == lastIndex, the element was already deleted from the stream
            
                mp[nums[lastIndex]].erase(lastIndex); // Delete the lastIndex from mp[nums[lastIndex]] set
                mp[nums[lastIndex]].insert(index); // Insert index into mp[nums[lastIndex]] set
                
                swap(nums[index],nums[lastIndex]); // Swap the values at index and lastIndex
            }
            nums.pop_back(); // Delete the last element from nums
            
            if(mp[val].size() == 0) mp.erase(val); // If the size of mp[val] is 0, val is absent from the stream and hence it is removed
            return 1;
        }
        
        int getRandom() {
            
            int randomIndex = rand() % nums.size(); // Get any random index from 0 to nums.length() - 1
            
            return nums[randomIndex]; // Return the value at that index
        }
        
};

int main(){
    
    Stream myStream;
    
    cout << myStream.insert(5) << endl;
    cout << myStream.insert(6) << endl;
    cout << myStream.insert(5) << endl;
    cout << myStream.remove(6) << endl;
    cout << myStream.remove(6) << endl;
    cout << myStream.getRandom() << endl;
    
    return 0;
}
