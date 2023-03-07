//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    unordered_map<char,int> mp;
    int i=0,j=0;
    int n = s.size();
    if(k>n){
        return -1;
    }
    int count = 0;
    int mx = -1;
    while(j<n){
        //perform calculation
        mp[s[j]]++;
        //adjust starting index index after condition is violated
        if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            //store answer when condition satisfies
        }else if(mp.size()==k){
            mx = max(mx,j-i+1);
        }
        j++;
        
    }
    
    return mx;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends