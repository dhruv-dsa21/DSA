//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    sort(arr,arr+n);
	     int count = 0;
	    for(int i = n-1;i>=2;i--){
	        int k = i-1;
	        int j = 0;
	       
	        while(j<k){
	           int x = arr[i];
	           int y = arr[j];
	           int z = arr[k];
	          
	               if(y+z==x){
	                   count++;
	                   j++;
	                   k--;
	               }else if(y+z<x){
	                   j++;
	               }else if(y+z>x){
	                   k--;
	               }
	           
	        }
	       
	    }
	     return count;
	    
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends