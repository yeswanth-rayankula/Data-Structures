//Time Complexity  --> O(V+E)
//Space Complexity --> O(V+E)
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<int> graph[V];
        vector<int> inDegree(V,0);
        queue<int> q;
        int count=0;
        for(auto i: edges)
        {
            graph[i[0]].push_back(i[1]);
            inDegree[i[1]]++;
        }
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            count++;
            for(auto k: graph[a])
            {
                inDegree[k]--;
                if(inDegree[k]==0)
                    q.push(k);
            }
        }
        return count!=V;

    }
};