/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sol;
    bool solve(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)
        {
            return 0;
        }

        bool a=solve(root->left,p,q);
        bool b=solve(root->right,p,q);

        if(root->val == p->val && (a || b))
        {
            sol = root;
        }
        if(root->val == q->val && (a || b))
        {
            sol = root;
        }
        if(a && b && !sol)
        {
            sol = root;
        }
        if(a || b || root->val==p->val || root->val==q->val)
            return 1;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return sol;
    }
};