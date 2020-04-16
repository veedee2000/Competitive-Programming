class CustomStack {
    vector<int>stack;
    vector<int>added;
    int max;
public:
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(max){
            stack.push_back(x);
            added.push_back(0);
            --max;
        }
    }
    
    int pop() {
        if(!stack.size()) return -1;
        int value = stack.back() + added.back(),toAddedTop = added.back();
        stack.pop_back();
        added.pop_back();
        if(added.size()) added[(int) added.size() - 1] += toAddedTop;
        ++max;
        return value;
    }
    
    void increment(int k, int val) {
        if(!added.size()) return;
        k = min(k,(int) added.size());
        added[k - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
