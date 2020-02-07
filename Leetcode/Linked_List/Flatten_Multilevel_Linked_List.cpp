/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        Node *node = new Node(head -> val),*ret = node;
        if(head -> child){
            Node* temp = flatten(head -> child);
            node -> next = temp;
            temp -> prev = node;
        }
        while(node -> next) node = node -> next;
        if(head -> next){
            Node* temp = flatten(head -> next);
            node -> next = temp;
            temp -> prev = node;
        }
        return ret;
    }
};
