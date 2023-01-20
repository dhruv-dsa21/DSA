class Solution
{
    public:
    set<vector<int>> st;
        void solve(vector<int> &nums, vector<int> temp, vector< vector< int>> &ans, int idx, int n)
        {
            if (idx >= n)
            {
                if (temp.size() > 1)
                {
                    st.insert(temp);
                }
                return;
            }
            if (temp.size() > 0)
            {
                if (temp[temp.size() - 1] <= nums[idx])
                {
                    temp.push_back(nums[idx]);
                    solve(nums, temp, ans, idx + 1, n);
                    temp.pop_back();
                    solve(nums, temp, ans, idx + 1, n);
                }
                else
                {
                    solve(nums, temp, ans, idx + 1, n);
                }
            }
            else
            {   temp.push_back(nums[idx]);
                solve(nums, temp, ans, idx + 1, n);
                temp.pop_back();
                solve(nums, temp, ans, idx + 1, n);
            }
        }
    vector<vector < int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        vector<vector < int>> ans;
        solve(nums, temp, ans, 0, n);
        for(auto it:st){
            ans.push_back(it);
        }
        
        return ans;
    }
};