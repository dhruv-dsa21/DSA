//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int &x,int &y,int &z,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return -1e8;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int f = solve(n-x,x,y,z,dp);
        int s = solve(n-y,x,y,z,dp);
        int t = solve(n-z,x,y,z,dp);
        return dp[n] = 1 + max(f,max(s,t));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
       
        for(int i=1;i<=n;i++){
            int f = -1e8,s=-1e8,t=-1e8;
            if(i-x>=0){
                f = dp[i-x];
            }
            if(i-y>=0){
                s = dp[i-y];
            }
             if(i-z>=0){
                t = dp[i-z];
            }
            dp[i] = 1 + max(f,max(s,t));
        }
       
        if(dp[n]<0){
            return 0;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends