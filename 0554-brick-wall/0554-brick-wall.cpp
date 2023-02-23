class Solution
{
    public:
        int leastBricks(vector<vector < int>> &wall)
        {
            int n = wall.size();
            int ans = 0;
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                int prefix = 0;
               
                    for (int j = 0; j < wall[i].size() - 1; j++)
                    {
                        prefix += wall[i][j];
                        mp[prefix]++;
                    }
                
            }
            
            for (auto it: mp)
            {
                ans = max(ans,it.second);
            }
            return n-ans;
        }
};