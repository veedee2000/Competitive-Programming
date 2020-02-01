class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>forward,reverse;
    int frontElement;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        forward.push(x);
        if(forward.size() == 1) frontElement = forward.top();
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!forward.empty()){
            reverse.push(forward.top());
            forward.pop();
        }
        int popped = reverse.top();
        reverse.pop();
        if(!reverse.empty()) frontElement = reverse.top();
        while(!reverse.empty()){
            forward.push(reverse.top());
            reverse.pop();
        }
        return popped;
    }
    
    /** Get the front element. */
    int peek() {
        return frontElement;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return forward.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
