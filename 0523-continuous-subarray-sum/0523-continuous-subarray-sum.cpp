class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        if(n==1){
            return false;
        }
        
        long long prefix = 0;
        
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(prefix%k==0&&i>=1){
                return true;
            }
            int rem = prefix%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2){
                    return true;
                }
            }else{
                mp[rem] = i;
            }
            
        }
        return false;
    }
};