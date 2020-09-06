Node *flatten(Node *root){
    if(!root) return NULL;
    Node *head1 = flatten(root -> next);
    Node *head2 = root -> bottom;
    Node *traverse = root;
    while(head1 and head2){
        if(head1 -> data < head2 -> data) traverse -> bottom = head1, head1 = head1 -> bottom;
        else traverse -> bottom = head2, head2 = head2 -> bottom;
        traverse = traverse -> bottom;
    }
    if(head1) traverse -> bottom = head1;
    if(head2) traverse -> bottom = head2;
    root -> next = NULL;
    return root;
}
