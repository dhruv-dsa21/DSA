//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        set<vector<int>> ans;
        for(int i = 0;i<n-3;i++){
            for(int j = i+1;j<n-2;j++){
                int p = j+1;
                int q = n-1;
                while(p<q){
                    vector<int> v;
                    int a = arr[i];
                    int b = arr[j];
                    int c = arr[p];
                    int d = arr[q];
                    if(a + b + c + d==k){
                        v.push_back(a);
                        v.push_back(b);
                        v.push_back(c);
                        v.push_back(d);
                        ans.insert(v);
                        p++;
                        q--;
                    }else if(a + b + c + d<k){
                        p++;
                    }else if(a + b + c + d>k){
                        q--;
                    }
                }
            }
        }
        vector<vector<int>> results;
        for(auto it:ans){
            results.push_back(it);
        }
        return results;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends