class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int n = nums.size();
        int i = 0,j=0;
        int pro = 1;
        int count = 0;
        while(j<n){
            
                pro = pro*nums[j];
                
            while(pro>=k){
                pro = pro/nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
      
        return count;
        
    }
};