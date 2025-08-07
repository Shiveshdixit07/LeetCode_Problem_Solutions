class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += grid[i][i];
        }

        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }
            vector<int> prev(n, -1), curr(n, -1);

            prev[n - 1] = grid[0][n - 1];

            for (int ri = 1; ri < n - 1; ri++)
            {
                curr.resize(n, -1);
                for (int i = 0; i < n; i++)
                {
                    if (prev[i] < 0)
                        continue;
                    if (i > 0)
                        curr[i - 1] =
                            max(curr[i - 1], prev[i] + grid[ri][i - 1]);
                    if (i < n - 1)
                        curr[i + 1] =
                            max(curr[i + 1], prev[i] + grid[ri][i + 1]);
                    curr[i] = max(curr[i], prev[i] + grid[ri][i]);
                }
                swap(prev, curr);
            }
            ans += prev[n - 1];
        }
        return ans;
    }
};