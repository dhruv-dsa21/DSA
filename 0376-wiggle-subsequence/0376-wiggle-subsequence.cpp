class Solution {
public:
    int dp[1001][1001][2];
    int solve(vector<int> &nums,int flag,int prev,int curr,int &n){
        if(curr>=n){
            return 0;
        }
        int pick = 0;
        int nopick = 0;
        if(dp[prev][curr][flag]!=-1){
            return dp[prev][curr][flag];
        }
        
        //recursive calls are very similar to LIS quesn.
        nopick = 0 + solve(nums,flag,prev,curr+1,n);
      
         if(flag==1&&nums[curr]>nums[prev]){
            pick = 1 + solve(nums,flag-1,curr,curr+1,n);
        }else if(flag==0&&nums[curr]<nums[prev]){
            pick = 1 + solve(nums,flag+1,curr,curr+1,n);
        }
        return dp[prev][curr][flag] = max(pick,nopick);
            
    }
    int wiggleMaxLength(vector<int>& nums) {
        int flag = 1;
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        // we will put 2 recursive calls with different flag values 
        //because sequence can be with +ve and -ve difference initially
        return 1 + max(solve(nums,1,0,1,n),solve(nums,0,0,1,n));
    }
};