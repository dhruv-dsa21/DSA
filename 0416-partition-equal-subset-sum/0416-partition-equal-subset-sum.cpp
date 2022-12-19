class Solution {
public:
//      bool solve(vector<int> &arr,int sum,int n,vector<vector<int>> &dp){
       
//        if(sum==0){
//            return true;
//        }
//        if(n<0&&sum>0){
//            return false;
//        }
        
//         if(dp[n][sum]!=-1){
//             return dp[n][sum];
//         }
        
//         bool take,nottake;
//         nottake = solve(arr,sum,n-1,dp);
//         if(arr[n]<=sum){
//             take = solve(arr,sum-arr[n],n-1,dp);
//         }
            
        
//         return dp[n][sum] = take||nottake;
//     }
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
           
        vector<bool> temp(sum+1,false);
            temp[0] = true;
           
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=sum;j++){
        //         if(i==0&&j==0){
        //             dp[i][j] = true;
        //         }
        //         if(j==0){
        //             dp[i][j] = true;
        //         }
        //         if(i==0&&j>0){
        //             dp[i][j] = false;
        //         }
        //     }
        // }
        for(int i=1;i<=n;i++){
            vector<bool> dp(sum+1);
            dp[0] = true;
            for(int j=1;j<=sum;j++){
                bool take =false;
                bool notake;
               
                if(nums[i-1]<=j){
                    take  = temp[j-nums[i-1]];
                }
                notake = temp[j];
                dp[j] = (take||notake);
            }
            temp = dp;
        }
        return temp[sum];
    }
};