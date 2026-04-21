
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> sol;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int data;
            while(n--)
            {
                TreeNode* a=q.front();
                q.pop();
                data = a->val;
                if(a->left)
                {
                    q.push(a->left);
                }
                if(a->right)
                {
                    q.push(a->right);
                }
            }
            sol.push_back(data);
        }
        return sol;
    }
};