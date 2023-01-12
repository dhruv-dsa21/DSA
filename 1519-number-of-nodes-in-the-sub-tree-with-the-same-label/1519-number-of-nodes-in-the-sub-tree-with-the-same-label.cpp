class Solution {
public:
    vector<int> dfs(vector<vector<int>> &graph,string &labels,vector<int> &ans,int node,int prev){
        vector<int> curr_node(26,0);
        
        curr_node[labels[node]-'a'] = 1;
        for(auto it:graph[node]){
            if(it==prev){
                continue;
            }
            vector<int> temp(26,0);
                temp = dfs(graph,labels,ans,it,node);
            for(int i=0;i<26;i++){
                curr_node[i]+=temp[i];
            }
        }
        ans[node] = curr_node[labels[node]-'a'];
        return curr_node;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)  {
           vector<vector<int>> a(n);
        for(auto x:edges){
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        
        vector<int> ans(n,0);
         dfs(a,labels,ans,0,-1);
        return ans;
   }
};