class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
       
     vector<unordered_set<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
       
        vector<int> odds;
       for(int i=1;i<=n;i++){
           if(adj[i].size()%2!=0){
               odds.push_back(i);
           }
       }
        if(odds.size()>4||odds.size()%2!=0){
            return false;
        }
        else if(odds.size()==4){
            int a,b,c,d;
            a = odds[0];
            b = odds[1];
            c = odds[2];
            d = odds[3];
            if(adj[a].find(b)==adj[a].end()&&adj[c].find(d)==adj[c].end()){
                return true;
            }
            if(adj[a].find(c)==adj[a].end()&&adj[b].find(d)==adj[b].end()){
                return true;
            }
            if(adj[a].find(d)==adj[a].end()&&adj[b].find(c)==adj[b].end()){
                return true;
            }
            return false;
        }
        else if(odds.size()==2){
            int a,b;
            a = odds[0];
            b = odds[1];
            if(adj[a].find(b)==adj[a].end()){
                return true;
            }else{
                for(int i=1;i<=n;i++){
                    if(adj[a].find(i)==adj[a].end()&&adj[b].find(i)==adj[b].end()){
                        return true;
                    }
                }
                return false;
            }
        }
        return true;
    }
};