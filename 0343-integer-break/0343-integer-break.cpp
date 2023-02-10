class Solution {
public:
    int solve(int n,vector<int> &dp){
      
        if(n==1||n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int maxi = INT_MIN;
        for(int i=1;i<n;i++){
            maxi = max(maxi,max(solve(n-i,dp)*i,i*(n-i)));
        }
        return dp[n] = maxi;
        
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};