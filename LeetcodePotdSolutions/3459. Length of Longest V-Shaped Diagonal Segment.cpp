class Solution
{
public:
    int n, m;
    int dp[500][500][5][2];
    int solve(vector<vector<int>> &g, int i, int j, int curr, bool turn,
              int dir)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] != curr)
            return 0;
        if (dp[i][j][dir + 1][turn] != -1)
            return dp[i][j][dir + 1][turn];
        int moves = 0;
        if (dir == -1)
        {
            moves = max(solve(g, i + 1, j + 1, 2, turn, 0), moves);
            moves = max(solve(g, i + 1, j - 1, 2, turn, 1), moves);
            moves = max(solve(g, i - 1, j - 1, 2, turn, 2), moves);
            moves = max(solve(g, i - 1, j + 1, 2, turn, 3), moves);
        }
        else
        {
            int next = curr == 2 ? 0 : 2;
            if (dir == 0)
            {
                if (!turn)
                {
                    moves = solve(g, i + 1, j - 1, next, 1, 1);
                }
                moves = max(moves, solve(g, i + 1, j + 1, next, turn, 0));
            }
            else if (dir == 1)
            {
                if (!turn)
                {
                    moves = solve(g, i - 1, j - 1, next, 1, 2);
                }
                moves = max(moves, solve(g, i + 1, j - 1, next, turn, 1));
            }
            else if (dir == 2)
            {
                if (!turn)
                {
                    moves = solve(g, i - 1, j + 1, next, 1, 3);
                }
                moves = max(moves, solve(g, i - 1, j - 1, next, turn, 2));
            }
            else
            {
                if (!turn)
                {
                    moves = solve(g, i + 1, j + 1, next, 1, 0);
                }
                moves = max(moves, solve(g, i - 1, j + 1, next, turn, 3));
            }
        }
        return dp[i][j][dir + 1][turn] = moves + 1;
    }
    int lenOfVDiagonal(vector<vector<int>> &g)
    {
        int ans = 0;
        n = g.size();
        m = g[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 1)
                {
                    ans = max(ans, solve(g, i, j, 1, 0, -1));
                }
            }
        }
        return ans;
    }
};