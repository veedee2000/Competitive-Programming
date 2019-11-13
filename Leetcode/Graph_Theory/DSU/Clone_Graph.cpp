/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        static unordered_map<Node*,Node*>mp;  // Static is needed
        if(!node) return NULL;
        if(mp.find(node) == mp.end()){  // Finding if the key exists
            Node* new_node = new Node();  // The parenthesis are imp!!!
            new_node -> val = node -> val;
            mp[node] = new_node;
            for(auto x:node -> neighbors){
                new_node -> neighbors.push_back(cloneGraph(x));
            }
        }
        return mp[node];
    }
};
