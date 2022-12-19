class Solution {
public:
     bool solve(vector<int> &arr,int sum,int n,vector<vector<int>> &dp){
       
       if(sum==0){
           return true;
       }
       if(n<0&&sum>0){
           return false;
       }
        
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        bool take,nottake;
        nottake = solve(arr,sum,n-1,dp);
        if(arr[n]<=sum){
            take = solve(arr,sum-arr[n],n-1,dp);
        }
            
        
        return dp[n][sum] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        
        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,sum,n-1,dp);
    }
};