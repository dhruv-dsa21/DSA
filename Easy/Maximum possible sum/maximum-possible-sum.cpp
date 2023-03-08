//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long int returnMaxSum(int A[], int B[], int n)
	{
	     int i=0,j=0;
	     unordered_map<int,int> mp;
	     int sum = 0;
	     int mx = INT_MIN;
	     while(j<n){
	         sum+=B[j];
	         mp[A[j]]++;
	         
	          if(mp.size()<(j-i+1)){
	             while(mp.size()<(j-i+1)){
	            sum-=B[i];
	             mp[A[i]]--;
	             if(mp[A[i]]==0){
	                 mp.erase(A[i]);
	             }
	             i++;
	            }
	            
	         } 
	         if(mp.size()==(j-i+1)){
	             mx = max(mx,sum);
	         }
	         j++;
	     }
	     return mx;
	}

};
	  


//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,i;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	      cin>>a[i];
	     for(i=0;i<n;i++)
	     cin>>b[i];
        
        

        Solution ob;
		cout << ob.returnMaxSum(a, b, n);
        
	    cout << "\n";
	     
    }
    return 0;
}




// } Driver Code Ends