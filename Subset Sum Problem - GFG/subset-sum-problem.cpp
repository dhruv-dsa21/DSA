//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int> &arr,int sum,int n,vector<vector<int>> &dp){
       
       if(sum==0){
           return true;
       }
       if(n<0&&sum>0){
           return false;
       }
        
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        bool take,nottake;
        nottake = solve(arr,sum,n-1,dp);
        if(arr[n]<=sum){
            take = solve(arr,sum-arr[n],n-1,dp);
        }
            
        
        return dp[n][sum] = take||nottake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends