
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;   
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        int sol=1,k=0;
        while(!q.empty())
        {
            int n=q.size();
            long long int i=INT_MAX,j=INT_MIN;
            long long base = q.front().second;
            while(n--)
            {
                TreeNode* a=q.front().first;
                long long int ind = q.front().second-base;
                q.pop();
                i=min(ind,i);
                j=max(j,ind);
                if(a->left)
                    q.push({a->left,2*ind+1});
                if(a->right)
                    q.push({a->right,2*ind+2});
            }
            if(sol<(j-i+1))
                sol = j-i+1;
        }
        return sol;
    }
};