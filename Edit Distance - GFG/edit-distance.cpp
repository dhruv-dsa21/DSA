//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(string &s,string &t,int m,int n,vector<vector<int>> &dp){
      if(m<0){
          return n+1;
      }
      if(n<0){
          return m+1;
      }
      if(dp[m][n]!=-1){
          return dp[m][n];
      }
      if(s[m]==t[n]){
          return dp[m][n] = solve(s,t,m-1,n-1,dp);
      }else{
      int ins =  solve(s,t,m,n-1,dp);
      int del =  solve(s,t,m-1,n,dp);
      int rep =  solve(s,t,m-1,n-1,dp);
      return dp[m][n] = 1 + min(ins,min(del,rep));
      }
     
  }
    int editDistance(string s, string t) {
       int m = s.size();
       int n = t.size();
    //   vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
       vector<int> dp(n+1);
       
      for(int i=0;i<=n;i++){
          dp[i] = i;
      }
       
       for(int i=1;i<=m;i++){
           vector<int> temp(n+1);
           temp[0]= i;
           for(int j=1;j<=n;j++){
               if(s[i-1]==t[j-1]){
                   temp[j] = dp[j-1];
               }else{
                   int ins = temp[j-1];
                   int del = dp[j];
                   int rep = dp[j-1];
                   temp[j] = 1 + min(ins,min(del,rep));
               }
           }
           dp = temp;
           
       }
       return dp[n];
       
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends