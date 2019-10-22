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
    int ans = 1;
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        dfs(root, 1);
        return ans;
    }
    
    void dfs(Node* root, int current){
        ans = max(ans, current);
        for(auto x: root->children){
            dfs(x, current + 1);
        }
    }
};
