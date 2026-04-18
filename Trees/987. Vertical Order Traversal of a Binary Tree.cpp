
class Solution {
public:
    // void solve(TreeNode* root, int i, map<int,vector<int>>& mp)
    // {
    //     if(root==NULL)
    //         return ;
    //     mp[i].push_back(root->val);
    //     solve(root->left,i-1,mp);
    //     solve(root->right,i+1,mp);
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
            unordered_map<int,vector<int>> umap;
            while(n--)
            {
                TreeNode* a=q.front().first;
                int i=q.front().second;
                umap[i].push_back(a->val);
                q.pop();
                if(a->right)
                {
                    q.push({a->right,i+1});
                }
                if(a->left)
                {
                    q.push({a->left,i-1});
                }

            }
            for (auto &p : umap)
            {
                auto &vec = p.second;
                sort(vec.begin(), vec.end());  
                mp[p.first].insert(mp[p.first].end(), vec.begin(), vec.end());
            }
           
        }
        
        for(auto i: mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};