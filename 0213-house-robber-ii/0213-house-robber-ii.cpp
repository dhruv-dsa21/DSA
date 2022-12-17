class Solution {
public:
int solve(int idx,int n,vector<int> &nums,vector<int> &dp){
    if(idx>=n){
        return 0;
    }
    int pick = 0;
    int nopick = 0;
    if(dp[idx]!=-1){
        return dp[idx];
    }
     pick = nums[idx] + solve(idx+2,n,nums,dp);
    nopick = solve(idx+1,n,nums,dp);
    return dp[idx] = max(pick,nopick);
   
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        
         if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(n+1,-1);
       
        int mx1 = solve(0,n-1,nums,dp);
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        int mx2 = solve(1,n,nums,dp);
        return max(mx1,mx2);

    }
};