class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2];
        int n = nums.length;
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        
        for(int i=0;i<n;i++){
            if(mp.containsKey(nums[i])){
                
                ans[0] = mp.get(nums[i]);
                ans[1] = i;
                return ans;
            }else{
                mp.put(target-nums[i],i);
            }
        }
        return new int[2];
       
        
    }
}