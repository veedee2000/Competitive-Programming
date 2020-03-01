/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head or !root) return 0;
        return f(head,root) or isSubPath(head,root ->left) or isSubPath(head,root -> right);
    }
    
    bool f(ListNode* head, TreeNode* root){
        if(!head) return 1;
        if(!root) return 0;
        if(head -> val != root -> val) return 0;
        return f(head -> next,root -> left) or f(head -> next,root -> right);
    }
};
