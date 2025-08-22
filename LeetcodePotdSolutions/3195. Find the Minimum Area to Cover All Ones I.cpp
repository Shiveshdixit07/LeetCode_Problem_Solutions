class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int ans = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        int sx = -1, sy = -1, ex = -1, ey = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    if (sy == -1)
                        sy = i;
                    ey = i;
                    if (sx == -1)
                        sx = j;
                    else
                        sx = min(sx, j);
                    ex = max(ex, j);
                }
            }
        }
        return (ey - sy + 1) * (ex - sx + 1);
    }
};