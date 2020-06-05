#include<iostream>
#include<unordered_set>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this -> val = val;
        next = NULL;
    }
};

void reverse(ListNode* head){
    ListNode *temp1 = NULL, *temp2, *trav = head;
    unordered_set<ListNode*>s;
    while(!s.count(trav)){
        temp2 = trav -> next;
        trav -> next = temp1;
        temp1 = trav;
        trav = temp2;
        s.insert(temp1);
    }
    head -> next = temp1;
}

int main(){
    

    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next -> next = head;
    
    unordered_set<ListNode*>s;

    reverse(head);

    while(!s.count(head)) cout << head -> val << " ", s.insert(head), head = head -> next;

    return 0;
}
