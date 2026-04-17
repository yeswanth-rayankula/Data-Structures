
class Solution {
public:
    int sol = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right==NULL)
        {
            sol = max(sol, root->val);
            return root->val;
        }
        int l= max(0,solve(root->left));
        int r= max(0,solve(root->right));

        sol = max(sol, l+r+root->val);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sol;
    }
};