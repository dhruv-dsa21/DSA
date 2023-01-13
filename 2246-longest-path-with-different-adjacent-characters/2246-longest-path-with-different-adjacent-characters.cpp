class Solution {
public:
    // vector<int> child[100001];
    // int ans;
    // int dfs(string &s, int curr_node)
    // {
    //     if(child[curr_node].empty())return 1;
    //     int mx1 = 0, mx2 =0;
    // // traversing over all the child nodes of the curr_node
    //     for(auto &child_node : child[curr_node])
    //     {
    //     // recursively trying for child nodes
    //         int len = dfs(s, child_node);
    //         ans = max(ans , len);
    //  // rejecting the current node if it's of same character
    //         if(s[curr_node] == s[child_node])continue;
    //  // updating the mx1 and mx2 paths that we can take from all the children of the given node
    //         if(len > mx1)
    //         {
    //             mx2 = mx1;
    //             mx1 = len;
    //         }
    // //seecond max will be updated
    //         else mx2 = max(mx2 , len);
    //     }
    // // Update the result.
    // //Again, max1+mx2+1 means the length of the longest valid path 
    // //going through this node in the sub-tree rooted at this node
    //     ans = max(ans, 1 + mx1 + mx2);
    // //Adding 1 for the current node
    //     return 1 + mx1;
    // }
    int dfs(int node,vector<vector<int>> &graph,int &ans,string &s,int parent){
        int longest = 0;
        int seclongest = 0;
        for(auto it:graph[node]){
            if(it==parent){
                continue;
            }
           
            int childlongest =dfs(it,graph,ans,s,node);
            if(s[it]==s[node]){
               continue;
           }
            if(childlongest>seclongest){
                seclongest = childlongest;
            }
            if(seclongest>longest){
                swap(longest,seclongest);
            }
            
        }
       int koi_ek_accha =1+ max(longest,seclongest);
        int dono_acche = longest + seclongest + 1;
        int dono_bure = 1;
        ans = max({ans,koi_ek_accha,dono_acche,dono_bure});
        return max(koi_ek_accha,dono_bure);
    }
    int longestPath(vector<int>& parent, string s){
        
        int n = parent.size();
        vector<vector<int>> graph(n);
        for(int i=1;i<n;i++){
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
        int ans=0;
        dfs(0,graph,ans,s,-1);
        return ans;
    }
};