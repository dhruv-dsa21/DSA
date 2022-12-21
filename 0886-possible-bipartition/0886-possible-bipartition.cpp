
class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int node, vector<int> &coloured, int parent) {
        if(coloured[node]==-1) coloured[node] = 0;
        for(auto it: graph[node] ) {
            if(coloured[it]==-1) {
                if(coloured[node]==0) coloured[it]=1;
                else coloured[it] = 0;
                if(!dfs(graph,it,coloured,node)) return false;
            }
            else if(coloured[it] == coloured[node]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> coloured(v,-1);
        int parent = -1;
        for(int i=0;i<v;i++) {
            if(coloured[i]==-1) if( !dfs(graph, i, coloured, parent))return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        return isBipartite(graph);
    }
};// class Solution {
// public:
//     bool dfs(int node,int parent,vector<int> &vis,vector<int> adj[]){
//         vis[node] = 1;
//         for(auto it:adj[node]){
//             if(vis[it]==0){
//                 if(dfs(it,node,vis,adj)){
//                     return true;
//                 }
//                 else if(it!=parent){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         vector<int> adj[n+1];
//         for(auto it:dislikes){
//             adj[it[0]].push_back(adj[it[1]]);
//             adj[it[1]].push_back(adj[it[0]]);
//         }
//         vector<int> vis(n+1,0);
//         for(int i=1;i<=n;i++){
//             if(!vis[i]){
//                 if(dfs(i,-1,vis,adj)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };