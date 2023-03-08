class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int cnt = 0;
        int mx = INT_MIN;
        int i = 0,j=0;
        while(j<n){
            cnt+=abs(s[j]-t[j]);
            while(cnt>maxCost){
                cnt-=abs(s[i]-t[i]);
                i++;
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};