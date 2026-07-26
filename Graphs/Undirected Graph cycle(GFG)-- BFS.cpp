Time complexity -- O(V+E)
Space complexity -- O(V+E)

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> graph[V];
        vector<bool> vis(V,false);
        for(auto i: edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
    for (int i = 0; i < V; i++) 
    {

        if (vis[i]) continue;
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            if(vis[node]==true)
                continue;
            vis[node]=true;
            for(auto i: graph[node])
            {
                if(!vis[i])
                {
                    q.push({i,node});
                }
                else if(parent!=i)
                    return true;
            }
        }
       
      }
       return false;
    }
};