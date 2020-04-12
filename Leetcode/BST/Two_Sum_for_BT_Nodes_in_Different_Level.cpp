vector<int> findTwoSumBinaryTree(TreeNode* root,int target){
        if(!root) return {-1,-1};
	set<int>s,aux;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			TreeNode* curr = q.front();
			q.pop();
			if(s.count(target - curr -> val)) return {curr -> val,target - curr -> val};
			if(curr -> left) q.push(curr -> left);
			if(curr -> right) q.push(curr -> right);
			aux.insert(curr -> val);
		}
		for(auto element:aux) s.insert(element);
		aux.clear();
	}
	return {-1,-1}; // If no such pair is found
}
