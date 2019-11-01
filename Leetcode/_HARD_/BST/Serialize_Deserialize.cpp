/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        ans += to_string(root -> val) + " ";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            
            if(current -> left){
                q.push(current -> left);
                ans = ans + to_string(current -> left -> val) + " ";
            }
            else{
                ans += "null ";
            }
            
            if(current -> right){
                q.push(current -> right);
                ans = ans + to_string(current -> right -> val) + " ";
            }
            else{
                ans += "null ";
            }
        }
        cout<<ans;
        return ans;
    }
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s == ""){
            return NULL;
        }
        stringstream ss(s);
        string word;
        vector<int>v;
        while(ss >> word){
            // cout<<word<<" ";
            if(word == "null") v.push_back(INT_MIN);
            else v.push_back(stoi(word));
        }
        int i = 1;
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(0);
        root -> val = v[0];
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(v[i] != INT_MIN) {
                current -> left = new TreeNode(0);
                current -> left -> val = v[i++];
                q.push(current -> left);
            }
            else i++;
            
            if(v[i] != INT_MIN) {
                current -> right = new TreeNode(0);
                current -> right -> val = v[i++]; 
                q.push(current -> right);
            }
            else i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
