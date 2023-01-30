class Solution {
public:
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i;k<=j;k++){
            int res = cuts[j+1] - cuts[i-1] + solve(cuts,i,k-1,dp) + 
                solve(cuts,k+1,j,dp);
            mini = min(mini,res); 
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int k = cuts.size();
        vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz = cuts.size();
        
        return solve(cuts,1,sz-2,dp);
    }
};