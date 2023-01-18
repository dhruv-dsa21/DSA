class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int curr = 0;
        //Concept:-sliding window with variable window size
        //refer:-https://leetcode.com/problems/count-the-number-of-good-               subarrays/discuss/3052887/C%2B%2B-Solution-Sliding-Window
        
        //intution:- if a subarray is good subarray then rest of the    subarrays containing it will also be good sub array
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