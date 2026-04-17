
class Solution {
public:
    pair<int,bool> solve(TreeNode* root,bool balanced)
    {
        if(root==NULL)
        {
            return {0,true};
        }
        auto l = solve(root->left,balanced);
        auto r = solve(root->right,balanced);

        if(!l.second || !r.second)
            return {0, false};
        
        if(abs(l.first-r.first)>1)
        {
            return {0, false};
        }
        return {1+max(l.first,r.first), true};
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return solve(root,false).second;
    }
};