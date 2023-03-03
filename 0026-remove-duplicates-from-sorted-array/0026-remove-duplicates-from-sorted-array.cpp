class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
       int i=0;
        
        //How the heck is this an easy question?
        //So basically we will keep one pointer at
        //0 and other at 1 and after that we will
        //keep moving j until we find a different number
        //and then we will increment i and put j index 
        //element on it and by this process we will be able to 
        //seperate unique sorted array with rest of the array.
        for(int j = 1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
       
        
    }
};