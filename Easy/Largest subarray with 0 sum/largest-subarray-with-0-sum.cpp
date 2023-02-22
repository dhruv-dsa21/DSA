//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
         vector<int> prefix(n+1,0);
         int maxi = 0;
         for(int i=1;i<=n;i++){
             prefix[i] = prefix[i-1] + A[i-1];
             if(prefix[i]==0){
                 maxi = max(maxi,i);
             }
         }
         
         unordered_map<int,int> mp;
         
         for(int i=1;i<=n;i++){
             if(mp.find(prefix[i])==mp.end()){
                 mp[prefix[i]] = i;
             }
             maxi = max(maxi,i - mp[prefix[i]]);
         }
         return maxi;
         
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends