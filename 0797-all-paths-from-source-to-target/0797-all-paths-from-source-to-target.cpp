class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &ans,vector<int> &temp,int node,int end){
        temp.push_back(node);
        if(node==end){
            ans.push_back(temp);
        }else{
            for(auto it:graph[node]){
                
                dfs(graph,ans,temp,it,end);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph,ans,temp,0,n-1);
        return ans;
    }
};