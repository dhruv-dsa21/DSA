class Solution {
public:

   void dfs(int v, vector<int> adj[], vector<bool> &vis)
    {
        vis[v] = true;
        
        for(auto u: adj[v])
            if(vis[u] == false)
                dfs(u, adj, vis);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      if(connections.size() < n-1)
            return -1;
        
        int disconnected = 00;
        vector<int> adj[n];
        vector<bool> vis(n, false);
        
        for(auto e: connections)  //adj list
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(vis[i] == false)
            {
                disconnected++;
                dfs(i, adj, vis);
            }
        }
        
        return disconnected-1;
    }
};