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
        
        //created a prefix sum array 
        //and stored the prefix sum for 
        //every element.
        
        
         int maxi = 0;
         int prefix = 0;
         //Main Concept:- if at different indices
         //prefix sum of element remains same 
         //then that means sum of numbers between
         //them must have remained 0.
         
         //Now this problem is just the variation 
         //of 1st problem of doc i.e.
         //max distance between same elements.
         
         unordered_map<int,int> mp;
         
         for(int i=0;i<n;i++){
             prefix+=A[i];
             if(prefix==0){
                 maxi=  max(maxi,i+1);
             }
             if(mp.find(prefix)==mp.end()){
                 mp[prefix] = i;
             }
             maxi = max(maxi,i - mp[prefix]);
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