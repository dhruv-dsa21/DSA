class Solution {
public:
    int solve(vector<vector<int>>& events, int k,int idx, int &n, vector<vector<int>> &dp){
        if(idx>=n||k==0){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int i;
        for(i = idx+1;i<n;i++){
            if(events[idx][1]<events[i][0]){
                  break;
            }
         
        }
        return dp[idx][k] = max(events[idx][2]+solve(events,k-1,i,n,dp),solve(events,k,idx+1,n,dp));
        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,k,0,n,dp);
    }
};