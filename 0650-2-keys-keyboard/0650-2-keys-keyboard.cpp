class Solution {
public:
    int solve(int &n,int value,int copy,vector<vector<int>> &dp){
        if(value>n){
            return 1e8;
        }
        if(value==n){
            return 1;
        }
        if(dp[value][copy]!=-1){
            return dp[value][copy];
        }
        int fstep = 0;
        int sstep = 0;
        fstep = 1+solve(n,value+copy,copy,dp);
        sstep = 2+solve(n,2*value,value,dp);
       
        return dp[value][copy] = min(fstep,sstep);
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(n,1,1,dp);
        
    }
};