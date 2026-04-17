
class Solution {
public:
    int sol = 0;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=solve(root->left);
        int h=solve(root->right);
        sol = max(sol,l+h);
        return 1+max(l,h);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return root == NULL ? 0 : sol ;
    }
};