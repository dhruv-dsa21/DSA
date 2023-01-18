class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        int maxcurrsum = 0;
        int mincurrsum = 0;
        int minsum = INT_MAX;
        //New-Concept:-application of kadane's algo
        //If we want to find the max sum of a circular subarray 
        //then we need to find minimum subarray sum and maximum 
        //sub array sum.
        
        //The final answer will either be conventional max subarraysum
        //or we can find it by subtracting total sum-min subarray sum 
        //because the remaining will be the max of subarray in circular fashion
        //dry-run once to clear doubt.
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxcurrsum = maxcurrsum + nums[i];
            mincurrsum = mincurrsum + nums[i];
            if(maxsum<maxcurrsum){
                maxsum = maxcurrsum;
            }
            if(maxcurrsum<0){
                maxcurrsum = 0;
            }
            if(minsum>mincurrsum){
                minsum = mincurrsum;
            }
            if(mincurrsum>0){
                mincurrsum = 0;
            }
            
        }
        
        if(sum==minsum){
            return maxsum;
        }
        return max(maxsum,sum-minsum);
        
    }
};