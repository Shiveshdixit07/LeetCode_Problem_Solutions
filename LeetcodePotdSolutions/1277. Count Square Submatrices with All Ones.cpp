class Solution
{
public:
    int dp[301][301];
    int n, m;
    int countSquares(vector<vector<int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (mat[i][j])
                {
                    int right = dp[i][j + 1];
                    int down = dp[i + 1][j];
                    int diag = dp[i + 1][j + 1];
                    dp[i][j] = 1 + min({right, down, diag});
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};