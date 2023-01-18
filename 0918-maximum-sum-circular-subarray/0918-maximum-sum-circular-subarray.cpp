class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        int maxcurrsum = 0;
        int mincurrsum = 0;
        int minsum = INT_MAX;
        
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