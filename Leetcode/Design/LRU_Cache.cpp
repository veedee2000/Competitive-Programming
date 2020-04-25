class LRUCache {
public:
    
    struct ListNode {
        int key,value;
        ListNode *pre, *next;
        ListNode (int key,int value = 0){
            this -> key = key;
            this -> value = value;
            pre = NULL;
            next = NULL;
        }
    };
    
    unordered_map<int,ListNode*>mp;
    int capacity;
    ListNode *head, *tail;
    
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new ListNode (0);
        tail = new ListNode (0);
        head -> next = tail;
        tail -> pre = head;
    }
    
    int get(int key) {
        
        if(!mp.count(key)) return -1;
        
            ListNode *node = mp[key];
            
        // Removing the node from its current position
        
        node -> pre -> next = node -> next;
        node -> next -> pre = node -> pre;

        // Inserting node after head 
        
        ListNode *afterHead = head -> next;
        head -> next = node;
        node -> pre = head;
        node -> next = afterHead;
        afterHead -> pre = node;

        return node -> value;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            mp[key] -> value = value;
            get(key);
        }
        
        else{
            ListNode *node = new ListNode (key,value);
            ListNode *afterHead = head -> next;
            head -> next = node;
            node -> pre = head;
            node -> next = afterHead;
            afterHead -> pre = node;
            mp[key] = node;
            
            if(--capacity < 0){
                ListNode *toDelete = tail -> pre;
                tail -> pre = tail -> pre -> pre;
                tail -> pre -> next = tail;
                mp.erase(toDelete -> key);
                delete toDelete;
                capacity++;
            }
        }
        
        cout<<head -> next -> key<<" "<<tail -> pre -> key<<endl;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
