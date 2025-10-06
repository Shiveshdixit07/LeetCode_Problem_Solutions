int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution
{
public:
    int n;
    int m;
    bool dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid,
             int th)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] > th)
            return 0;
        if (i == n - 1 && j == m - 1)
            return 1;
        vis[i][j] = 1;
        for (int p = 0; p < 4; p++)
        {
            int I = i + dir[p][0];
            int J = j + dir[p][1];
            if (dfs(I, J, vis, grid, th))
                return 1;
        }
        return 0;
    }
    bool chk(int k, vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        return dfs(0, 0, vis, grid, k);
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int l = 0;
        int h = 2500;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (chk(mid, grid))
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};