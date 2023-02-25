class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // First thing first we will make the 2
        //numbers that we will change equal
        // That will handle the case of low score
        
        //AThere will always be 3 possiblities 
        //1) If both smallest number changed
       int case1 = nums.back() - nums[2];
        //2) If both largest number gets changed
        int case2 = nums[nums.size() - 3] - nums[0];
        //3) If smallest and largest number are changed
        int case3 = nums[nums.size() - 2] - nums[1];
        return min(case1,min(case2,case3));
        
        
    }
};