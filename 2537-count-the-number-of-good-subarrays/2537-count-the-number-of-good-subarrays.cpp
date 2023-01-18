class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int curr = 0;
        unordered_map<int,int> mp;
        int curr_idx = 0;
        
        for(int i=0;i<n;i++){
            curr+=mp[nums[i]];
            mp[nums[i]]++;
            while(curr>=k){
                res+=(n-i);
                curr-=mp[nums[curr_idx]]-1;
                mp[nums[curr_idx]]--;
                curr_idx++;
            }
        }
        return res;
    }
};