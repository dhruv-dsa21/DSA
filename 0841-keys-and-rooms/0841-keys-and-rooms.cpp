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
        //it's a simple problem of disconnected graph. 
        //if the graph is connected then we can reach to each room.
        //if it is a disconnected graph then we can't reach to each room.
        //so we will keep a count variable if it is greater than 1 then graph           is disconnected
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