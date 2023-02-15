//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // long long solve(int n,int &k,vector<long long int> &dp){
        
    //     if(n==1){
    //         return k;
    //     }
    //     if(n==2){
    //         return k*k;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     long long int diff = ((k-1)*(solve(n-1,k,dp)))%mod;
    //     long long int same = ((k-1)*(solve(n-2,k,dp)))%mod;
    //     return dp[n] = (diff + same)%mod;
    // }
    long long countWays(int n, int k){
        int mod = 1e9 + 7;
        vector<long long int> dp(n+1,-1);
        dp[1] = k;
        dp[2] = k*k;
        for(int i=3;i<=n;i++){
         long long int diff = ((k-1)*(dp[i-1]))%mod;
        long long int same = ((k-1)*(dp[i-2]))%mod;
        dp[i] = (diff+same)%mod;
        }
    return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends