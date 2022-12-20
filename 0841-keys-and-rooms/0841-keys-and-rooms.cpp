class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int> &vis,int node){
        
            vis[node] = 1;
        
        for(auto it:rooms[node]){
            if(!vis[it]){
                dfs(rooms,vis,it);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(rooms,vis,i);
                count++;
            }
            if(count>1){
                return false;
            }
        }
        return true;
        
    }
    
};