class Solution {
private:
    int helper(int idx, int pidx, int diff, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case
        if(idx == arr.size()) {
            return 0;
        }
        
        // Check if result is already computed
        if(dp[idx][pidx+1] != -1) {
            return dp[idx][pidx+1];
        }
        
        int take = 0, not_take = 0;
        
        // Include the current element if conditions are met
        if(pidx == -1 || arr[idx] - arr[pidx] == diff) {
            take = 1 + helper(idx+1, idx, diff, arr, dp);
        }
        
        // Exclude the current element
        not_take = 0 + helper(idx+1, pidx, diff, arr, dp);
        
        // Store the result in memoization table
        return dp[idx][pidx+1] = max(take, not_take);
    }

public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> dp;
        int ans = 1;
        for(int i=0;i<n;i++){
            int sum = 0;
            if(dp[arr[i]-difference]!=-1){
                dp[arr[i]] = 1 + dp[arr[i]-difference];
            }else{
                dp[arr[i]] = 1;
            }
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};