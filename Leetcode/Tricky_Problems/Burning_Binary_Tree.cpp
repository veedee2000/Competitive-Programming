int helper(TreeNode* root, TreeNode* target, int& dist) {
  if(!root) return 0;
  if(root==target) {
    calculatedown(target);
    dist=1;
    return -1;
  }
  int ldist=-1;
  int rdist=-1;
  int lh=helper(root->left, target, ldist);
  int rh=helper(root->right, target, rdist);
  
  if(ldist!=-1) {
    res=max(res,ldist+rh);
    dist=ldist+1;
    return max(lh,rh) +1;
  }
  
  if(rdist!=-1) {
    res=max(res,rdist+lh);
    dist=ldist+1;
    return max(lh,rh) +1;
  }
  
  return max(lh,rh) +1;
}

int calculatedown(TreeNode* root) {
  int lh=calculatedown(root->left);
  int rh=calculatedown(root->right);
  res=max(lh,rh);
  return max(lh,rh) +1;
}
