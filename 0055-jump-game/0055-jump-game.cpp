
class Solution {
public:
    bool solve(vector<int> &nums,int idx,int n,vector<int> &dp){
        if(idx>=n){
            return 
                true;
        }
        
        if(nums[idx]==0){
            return dp[idx] = 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        bool temp = false;
        for(int i = 1;i<=nums[idx];i++){
              bool curr = solve(nums,idx+i,n,dp);
            if(curr){
                return dp[idx] = true;
            }
         
                temp = temp||curr;
         }
        return dp[idx]= temp;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,n-1,dp);
    }
};