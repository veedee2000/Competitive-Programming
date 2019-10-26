/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int>v;
    vector<int> postorder(Node* root) {
        dfs(root);
        return v;
    }
    
    void dfs(Node* root){
        if(!root) return;
        for(int i = 0;i < root -> children.size();i++) dfs(root -> children[i]);
        v.push_back(root -> val);
    }
};
