class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int n = nums.size();
            int st = 1;
            int end = n - 2;
            if(n==1){
                return nums[0];
            }
            if (nums[0] != nums[1])
            {
                return nums[0];
            }
            if (nums[n - 1] != nums[n - 2])
            {
                return nums[n - 1];
            }
            while (st <= end)
            {
                int mid = st + (end - st) / 2;
                //if both adjacent numbers are not equal to the number then it is the single element.
                if(nums[mid-1]!=nums[mid]&&nums[mid+1]!=nums[mid]){
                    return nums[mid];
                }
                // one thing we observe if our mid index is even then it has even no. of elements on its left side and if its left adjacent number is equal then we are sure that our single number will be present on the left side of array from mid index.
                if (mid % 2 == 0)
                {
                    if (mid>0&&nums[mid - 1] == nums[mid])
                    {
                        end = mid-1;
                    }
                    else if (mid>0&&nums[mid - 1] != nums[mid])
                    {
                        st = mid+1;
                    }
                   
                }else{
                      if (mid>0&&nums[mid - 1] == nums[mid] )
                    {
                        st = mid+1;
                    }
                    else if (mid>0&&nums[mid - 1] != nums[mid])
                    {
                        end = mid-1;
                    }
                }
            }
            return -1;
        }
};