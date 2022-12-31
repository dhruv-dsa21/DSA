class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j,int m,int n,int count,int &ans){
        if(i<0||i>m-1||j<0||j>n-1||vis[i][j]==-1||grid[i][j]==-1){
            return 0;
        }
        if(grid[i][j]==2){
            if(count==0){
                return 1;
            }
        }
        vis[i][j] = -1;
        int a = solve(grid,vis,i+1,j,m,n,count-1,ans);
        int b = solve(grid,vis,i-1,j,m,n,count-1,ans);
        int c = solve(grid,vis,i,j+1,m,n,count-1,ans);
        int d = solve(grid,vis,i,j-1,m,n,count-1,ans);
        count++;
        vis[i][j] = 0;
        return a + b + c + d;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
     int st1;
     int st2;
        
        int count = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
                else if(grid[i][j]==1){
                    st1 = i;
                    st2 = j;
                }
            }
        }
        return solve(grid,vis,st1,st2,m,n,count,ans);
    }
};