class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int arocks) {
        int ans = 0;
        for(int i=0;i<capacity.size();i++){
            capacity[i] = capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]==0){
                ans++;
                continue;
            }else{
               if(arocks<capacity[i]){
                   break;
               }else{
                   ans++;
                   arocks-=capacity[i];
                   capacity[i] = 0;
                 }
            }
        }
        return ans;
        
    }
};