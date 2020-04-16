class MyLinkedList {
    
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int v = 0,ListNode* n = NULL){
            val = v;
            next = n;
        }
    };
    
public:
    /** Initialize your data structure here. */
    ListNode* head = NULL,*t = NULL;
    int size = 0;
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > size - 1) return -1;
        t = head;
        while(index--) t = t -> next;
        return t -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new ListNode(val,head);
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        t = head;
        if(!head) head = new ListNode(val);
        else{
            while(t -> next) t = t -> next;
            t -> next = new ListNode(val);
        }
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(!index) addAtHead(val);
        else{
            t = head;
            while(--index) t = t -> next;
            ListNode* temp = t -> next;
            t -> next = new ListNode(val,temp);
        }
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* temp;
        if(!index){
            temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }
        else{
            t = head;
            while(--index) t = t -> next;
            temp = t -> next;
            t -> next = t -> next -> next;
            temp -> next = NULL;
            delete temp;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
