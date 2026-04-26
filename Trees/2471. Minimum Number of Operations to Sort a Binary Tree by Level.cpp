class Solution {
public:
    int solve(vector<int> vec)
    {
        vector<int> temp = vec;
        int count = 0;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;

        for(int i=0;i<vec.size();i++)
        {
            mp[vec[i]] = i;
        }
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]!=temp[i])
            {
                int ind = mp[temp[i]];
                swap(vec[i],vec[ind]);
                mp[vec[i]]=i;
                mp[vec[ind]]=ind;

                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        if(!root)
            return 0;
        int sol = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n= q.size();
            vector<int> vec;
            while(n--)
            {
                TreeNode* x = q.front();
                vec.push_back(x->val);
                q.pop();
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
            }
            sol += solve(vec);
        }
        return sol;
    }
};