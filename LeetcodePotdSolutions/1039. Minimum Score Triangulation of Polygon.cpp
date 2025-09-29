class Solution
{
public:
    int dp[50][50];
    int solve(int i, int j, vector<int> &v)
    {
        if (j - i < 2)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans =
                min(ans, v[i] * v[j] * v[k] + solve(i, k, v) + solve(k, j, v));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, v.size() - 1, v);
    }
};