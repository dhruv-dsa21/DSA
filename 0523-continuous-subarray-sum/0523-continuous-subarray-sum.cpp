class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        if(n==1){
            return false;
        }
        vector<int> prefix(n+1,0);
        
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            if(prefix[i]%k==0&&i>1){
                return true;
            }
            int rem = prefix[i]%k;
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