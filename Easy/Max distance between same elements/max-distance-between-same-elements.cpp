//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int,int> mp;
       
       for(int i=0;i<n;i++){
           if(mp.find(arr[i])==mp.end()){
               mp[arr[i]] = i;
           }
       }
        int mx = 0;
        for(int i=0;i<n;i++){
            if(i!=mp[arr[i]]){
                mx = max(mx,i-mp[arr[i]]);
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends