class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<queries.size();i++){
            int x = queries[i];
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                  sum+=nums[i];
                if(sum>x){
                    ans.push_back(i);
                    break;
                 }
                
            }
            if(sum<=queries[i]){
                ans.push_back(n);
            }
        }
        return ans;
    }
};