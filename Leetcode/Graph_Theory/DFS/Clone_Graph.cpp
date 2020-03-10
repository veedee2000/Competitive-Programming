/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* newNode = new Node(node -> val);
        mp[node -> val] = newNode;
        for(auto x:node -> neighbors){
            if(!mp.count(x -> val)) newNode -> neighbors.push_back(cloneGraph(x));
            else newNode -> neighbors.push_back(mp[x -> val]);
        }
        return newNode;
    }
};
