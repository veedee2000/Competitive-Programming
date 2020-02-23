class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        set<int>s;
        for(auto x:leftChild){
            if(x == -1) continue;
            if(!s.count(x)) s.insert(x);
            else return 0;
        }
        
        for(auto x:rightChild){
            if(x == -1) continue;
            if(!s.count(x)) s.insert(x);
            else return 0;
        }
        
        if(s.size() != n - 1) return 0;
        int index = 0,root = -1;
        for(auto x:s){
            if(x != index) {root = index; break;}
        }
        if(root == -1) root = index;
        
        s.clear();
        queue<int>q;
        q.push(root);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr != -1){
                if(!s.count(curr)) s.insert(curr);
                else return 0;
                q.push(leftChild[curr]);
                q.push(rightChild[curr]);
            }
        }
        return s.size() == n;
    }
};
