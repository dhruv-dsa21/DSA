class Solution
{
    public:
        int leastBricks(vector<vector < int>> &wall)
        {
            int n = wall.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                int prefix = 0;
                if (wall[i].size() == 1)
                {
                    mp[wall[i][0]] = 0;
                }
                else
                {
                    for (int j = 0; j < wall[i].size() - 1; j++)
                    {
                        prefix += wall[i][j];
                        mp[prefix]++;
                    }
                }
            }
            int ans = INT_MAX;
            for (auto it: mp)
            {
                ans = min(ans, n - it.second);
            }
            return ans;
        }
};