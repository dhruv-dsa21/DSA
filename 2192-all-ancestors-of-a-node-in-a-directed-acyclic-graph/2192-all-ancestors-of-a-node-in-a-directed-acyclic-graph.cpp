class Solution
{
    public:
        vector<vector < int>> getAncestors(int n, vector<vector < int>> &edges)
        {
            vector<vector < int>> graph(n);
            vector<int> indegrees(n, 0);
            for (int i = 0; i < edges.size(); i++)
            {
                graph[edges[i][0]].push_back(edges[i][1]);
                indegrees[edges[i][1]]++;
            }
            queue<int> q;
            vector<vector < int>> ans(n);
            for (int i = 0; i < n; i++)
            {
                if (indegrees[i] == 0)
                {
                    q.push(i);
                    
                }
            }
           unordered_map<int,set<int>> mp;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it: graph[node])
                {
                  mp[it].insert(node);
                  for(auto curr: mp[node]){
                    mp[it].insert(curr);
                  }
                
                  
                   
                    indegrees[it]--;
                    if (indegrees[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
          for(int i=0;i<n;i++){
            for(auto it:mp[i]){
              ans[i].push_back(it);
            }
          }
            return ans;
        }
};