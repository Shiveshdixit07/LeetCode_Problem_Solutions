class Solution
{
public:
    int minimumTotal(vector<vector<int>> &t)
    {
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), 1e8));
        dp[0][0] = t[0][0];
        if (t.size() == 1)
            return t[0][0];
        int ans = INT_MAX;
        for (int i = 1; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].size(); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = t[i][j] + dp[i - 1][j];
                    if (i == t.size() - 1)
                        ans = min(ans, dp[i][j]);
                    continue;
                }
                dp[i][j] = t[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                if (i == t.size() - 1)
                    ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};