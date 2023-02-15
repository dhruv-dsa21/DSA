//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solve(int coins[],int n,int sum,vector<vector<long long int>> &dp){
      if(n==0){
          if(sum==0){
              return 1;
          }
          return 0;
      }
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      long long int pick = 0,nopick = 0;
      if(sum>=coins[n-1]){
          pick = solve(coins,n,sum-coins[n-1],dp);
      }
      nopick = solve(coins,n-1,sum,dp);
      return dp[n][sum] = pick + nopick;
  }
    long long int count(int coins[], int N, int sum) {
       
       vector<long long int> dp(sum+1,0);
        dp[0] = 1;
        for(int i=1;i<=N;i++){
            vector<long long int> temp(sum+1);
            temp[0] = 1;
            for(int j=1;j<=sum;j++){
                long long int pick = 0,nopick = 0;
                 if(j>=coins[i-1]){
                     pick = temp[j-coins[i-1]];
                 }
                  nopick = dp[j];
                
                 temp[j] = pick + nopick;
                
            }
            dp = temp;
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends