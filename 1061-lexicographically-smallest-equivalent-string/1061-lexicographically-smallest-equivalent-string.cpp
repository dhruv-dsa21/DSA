class Solution {
public:
    char dfs(unordered_map<char,vector<char>> &adj,char curr,vector<char> &vis){
        vis[curr-'a'] = 1;
        char min_curr = curr;
        for(auto it:adj[curr]){
            if(vis[it-'a']==0){
                min_curr = min(min_curr,dfs(adj,it,vis));
            }
        }
        return min_curr;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        unordered_map<char,vector<char>> adj;
        string ans;
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        for(int i=0;i<m;i++){
            char curr = baseStr[i];
            vector<char> vis(26,0);
            char temp = dfs(adj,curr,vis);
            ans.push_back(temp);
        }
//         vector<char> temp(26,-1);
//         int n = s1.size();
//         vector<vector<char>> groups;
//         string ans = "";
//         if(s1[0]==s2[0]){
//             groups.push_back({s1[0]});
//             temp[s1[0]-'a'] = 0;
//         }else{
//             groups.push_back({s1[0],s2[0]});
//             temp[s1[0]-'a'] = 0;
//             temp[s2[0]-'a'] = 0;
//         }
//         for(int i=1;i<n;i++){
//           int x = s1[i]-'a';
//             int y = s2[i]-'a';
//             if(temp[x]==-1&&temp[y]==-1){
//                  if(s1[i]==s2[i]){
//                      groups.push_back({s1[i]});
//                      temp[x] = groups.size()-1;
//                  }else{
//                 groups.push_back({s1[i],s2[i]});
//                 temp[x] = groups.size()-1;
//                 temp[y] = groups.size()-1;
//                  }

//             }
//             if(temp[x]==-1&&temp[y]!=-1){
//                 groups[temp[y]].push_back(s1[i]);
//                 temp[x] = temp[y];
//             }
//              if(temp[x]!=-1&&temp[y]==-1){
//                 groups[temp[x]].push_back(s2[i]);
//                 temp[y] = temp[x];
//             }
           
//         }
//         for(int i=0;i<groups.size();i++){
//             sort(groups[i].begin(),groups[i].end());
//         }
//         for(int i=0;i<baseStr.size();i++){
//             int idx = temp[baseStr[i]-'a'];
//             if(idx==-1){
//                 ans.push_back(baseStr[i]);
//             }else{
//                 ans.push_back(groups[idx][0]);
//             }
                
            
//         }
        return ans;
    }
};