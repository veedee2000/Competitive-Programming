class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>mp;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxFreq = max(maxFreq,++freq[x]);
        mp[freq[x]].push(x);
    }
    
    int pop() {
        int val = mp[maxFreq].top();
        freq[val]--;
        mp[maxFreq].pop();
        if(mp[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
