// DFS for Cycle detection in Undirected graph
// Time complexity - O(V+E)
// Space complexity - O(V+E)
class Solution {
  public:
    bool isCycle(int i,vector<vector<int>>& graph,vector<bool>& vis,int p)
    {
        vis[i]=true;
        // temp[i]=true;
        for(auto k: graph[i])
        {
            if(vis[k]==false)
            {
                if(isCycle(k,graph,vis,i))
                    return true;
            }
            else if(k!=p)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> graph(V);
        for(auto i: edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            
        }
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                // vector<bool> temp(V,false);
                if(isCycle(i,graph,vis,-1))
                    return true;
            }
        }
        return false;
    }
};