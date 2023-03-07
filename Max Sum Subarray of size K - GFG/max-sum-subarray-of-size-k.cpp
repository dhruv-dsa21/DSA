//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &nums , int N){
        int n = N;
        int j = 0;
        int i = 0;
        long sum = 0;
        long maxi = 0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1>K){
                sum-=nums[i];
                i++;
            }
            maxi = max(maxi,sum);
            j++;
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends