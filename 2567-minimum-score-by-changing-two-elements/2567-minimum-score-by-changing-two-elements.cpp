class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       int case1 = nums.back() - nums[2];
        int case2 = nums[nums.size() - 3] - nums[0];
        int case3 = nums[nums.size() - 2] - nums[1];
        return min(case1,min(case2,case3));
        
        
    }
};