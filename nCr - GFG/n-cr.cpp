//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if(r>n){
            return 0;
        }
        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        vector<int> dp(r+1,0);
        dp[0] = 1;
        int mod = 1000000007;
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(j==0){
        //             dp[i][j] = 1;
        //         }
        //     }
        // }
         for(int i=1;i<=n;i++){
             vector<int> temp(r+1,0);
             temp[0] = 1;
            for(int j=1;j<=r;j++){
                
                    temp[j] = (dp[j] + dp[j-1])%mod;
                
            }
            dp = temp;
        }
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends