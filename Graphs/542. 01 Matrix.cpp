class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int z=0;
        int a1[]={1,0,0,-1};
        int b1[]={0,-1,1,0};
        
        while(!q.empty())
        {
            int t=q.size();
            cout<<t;
            while(t--)
            {
                auto[c,d]=q.front();
                mat[c][d]=z;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int e=c+a1[i];
                    int f=d+b1[i];
                    if(e>=0 && f>=0 && e<n && f<m && vis[e][f]==false)
                    {
                        vis[e][f]=true;
                        q.push({e,f});
                    }
                }
            }
            z++;
        }
        return mat;
    }
};