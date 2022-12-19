class Solution {
public:
    bool dfs( vector<int> adj[],vector<int> &vis,int node,int end){
        if(node==end){
            return true;
        }
        if(vis[node]){
            return false;
        }
        vis[node] = true;
        bool ans = false;
        for(auto it:adj[node]){
            if(!vis[it]){
                ans = ans||dfs(adj,vis,it,end);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,vis,source,destination);
        
    }
};