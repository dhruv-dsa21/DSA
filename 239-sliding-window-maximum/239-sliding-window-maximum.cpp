class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
           list<int> l;
        
        int j = 0, i = 0;vector<int> v;
        
        while(j<nums.size()){
            if(j - i  < k){
                while(!l.empty() && l.back() < nums[j])
                    l.pop_back();
                l.push_back(nums[j]);
                j++;
            }
            if(j - i  == k ){
                v.push_back(l.front());
                if(nums[i] == l.front()){
                    l.pop_front();
                }
                i++;
            }
        }
        return v;
  }
};