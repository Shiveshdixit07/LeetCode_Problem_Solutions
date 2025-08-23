class Solution
{
public:
    int minArea(int ys, int ye, int xs, int xe, vector<vector<int>> &grid)
    {
        int ans = INT_MAX;
        int sx = -1, sy = -1, ex = -1, ey = -1;
        for (int i = ys; i < ye; i++)
        {
            for (int j = xs; j < xe; j++)
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
        if (sy == -1 || sx == -1 || ex == -1 || ey == -1)
            return 0;
        return (ey - sy + 1) * (ex - sx + 1);
    }
    int minimumSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int x = minArea(0, i, 0, m, grid);
                int y = minArea(i, n, 0, j, grid);
                int z = minArea(i, n, j, m, grid);

                ans = min(ans, x + y + z);

                x = minArea(i, n, 0, m, grid);
                y = minArea(0, i, 0, j, grid);
                z = minArea(0, i, j, m, grid);
                ans = min(ans, x + y + z);

                x = minArea(0, n, 0, j, grid);
                y = minArea(0, i, j, m, grid);
                z = minArea(i, n, j, m, grid);
                ans = min(ans, x + y + z);

                x = minArea(0, n, j, m, grid);
                y = minArea(0, i, 0, j, grid);
                z = minArea(i, n, 0, j, grid);
                ans = min(ans, x + y + z);
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = minArea(0, i, 0, m, grid);
                int y = minArea(i, j, 0, m, grid);
                int z = minArea(j, n, 0, m, grid);
                ans = min(ans, x + y + z);
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                int x = minArea(0, n, 0, i, grid);
                int y = minArea(0, n, i, j, grid);
                int z = minArea(0, n, j, m, grid);
                ans = min(ans, x + y + z);
            }
        }
        return ans;
    }
};