//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(vector<vector<int>> &mat,int i,int j,int &n,int &m,vector<vector<int>> &dp){
  if(i<0||i>=n||j<0){
      return 0;
  }
  if(dp[i][j]!=-1){
      return dp[i][j];
  }
  int left = 0,upleft = 0,downleft = 0;
  left = solve(mat,i,j-1,n,m,dp);
  upleft = solve(mat,i-1,j-1,n,m,dp);
  downleft = solve(mat,i+1,j-1,n,m,dp);
  return dp[i][j] = mat[i][j] + max(left,max(upleft,downleft));
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        int dp[n][m];
       
       for(int i=0;i<n;i++){
           dp[i][0] = M[i][0];
       }
       for(int j=1;j<m;j++){
           for(int i=0;i<n;i++){
               int left = 0,upleft = 0,downleft = 0;
               if(j<=m){
                   left = dp[i][j-1];
               }
               if(i>0){
                   upleft = dp[i-1][j-1];
               }
               if(i<n-1){
                   downleft = dp[i+1][j-1];
               }
               dp[i][j] = M[i][j] + max(left,max(upleft,downleft));
           }
       }
        int result = INT_MIN;
        for(int i=0;i<n;i++){
            result = max(result,dp[i][m-1]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends