class FirstUnique {
    
    struct ListNode{
        int val;
        ListNode *pre, *next;
        ListNode(int val){
            this -> val = val;
            pre = NULL,next = NULL;
        }
    };
    
    unordered_map<int,ListNode*>mp;
    unordered_map<int,int>cnt;
    ListNode *head, *tail;
public:
    FirstUnique(vector<int>& nums) {
        head = new ListNode(0);
        tail = new ListNode(0);
        head -> next = tail;
        tail -> pre = head;
        for(auto x:nums){
            add(x);
        }
    }
    
    int showFirstUnique() {
        if(head -> next == tail) return -1;
        else return head -> next -> val;
    }
    
    void add(int val) {
        if(!cnt.count(val)){
            ListNode *node = new ListNode(val);
            ListNode *beforeTail = tail -> pre;
            tail -> pre = node;
            node -> next = tail;
            node -> pre = beforeTail;
            beforeTail -> next = node;
            mp[val] = node;
            cnt[val]++;
        }
        else if(cnt[val] == 1){
            ListNode *node = mp[val];
            ListNode* beforeNode = node -> pre;
            beforeNode -> next = node -> next;
            node -> next -> pre = beforeNode;
            node -> pre = node -> next = NULL;
            delete node;
            mp.erase(val);
            cnt[val]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
