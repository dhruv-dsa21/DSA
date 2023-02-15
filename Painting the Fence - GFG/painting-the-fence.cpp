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
        if(n==1){
            return k;
        }
        long long int prev1 = k;
        long long int prev2 = k*k;
        for(int i=3;i<=n;i++){
         long long int diff = ((k-1)*(prev2))%mod;
        long long int same = ((k-1)*(prev1))%mod;
        prev1 = prev2;
        prev2 = (diff+same)%mod;
        }
    return prev2;
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