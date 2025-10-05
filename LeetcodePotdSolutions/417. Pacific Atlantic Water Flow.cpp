int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution
{
public:
    int n;
    int m;
    vector<vector<int>> vis;
    void dfs(int i, int j, vector<vector<int>> &h, int prev)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] > 0 ||
            h[i][j] < prev)
            return;
        vis[i][j]++;
        for (int p = 0; p < 4; p++)
        {
            int I = dir[p][0] + i;
            int J = dir[p][1] + j;
            dfs(I, J, h, h[i][j]);
        }
        return;
    }
    void dfs2(int i, int j, vector<vector<int>> &h, int prev)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] > 1 ||
            h[i][j] < prev)
            return;
        vis[i][j] += 2;
        for (int p = 0; p < 4; p++)
        {
            int I = dir[p][0] + i;
            int J = dir[p][1] + j;
            dfs2(I, J, h, h[i][j]);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        vector<vector<int>> ans;
        n = h.size();
        m = h[0].size();
        vis = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, h, -1);
        }
        for (int j = 1; j < m; j++)
        {
            dfs(0, j, h, -1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs2(i, m - 1, h, -1);
        }
        for (int j = 0; j < m - 1; j++)
        {
            dfs2(n - 1, j, h, -1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 3)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};