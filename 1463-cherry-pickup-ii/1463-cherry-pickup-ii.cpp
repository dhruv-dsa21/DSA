class Solution {
public:
    int dp[71][71][71];
    int solve(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid){
        if(j1<0||j1>n-1||j2<0||j2>n-1){
            return -1e8;
        }
        if(i==m-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi = -1e8;
        for(int k=-1;k<=1;k++){
            for(int j=-1;j<=1;j++){
                int value = 0;
                if(j1==j2){
                    value = grid[i][j1];
                }else{
                    value = grid[i][j1]+grid[i][j2];
                }
            maxi = max(maxi,value + solve(i+1,j1+k,j2+j,m,n,grid));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n-1,m,n,grid);
    }
};