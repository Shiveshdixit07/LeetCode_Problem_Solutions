class Solution
{
public:
    vector<string> ans;
    int dp[101][101];
    int solve(int i, int prev, vector<int> &g, int n)
    {
        if (i == n)
            return dp[i][prev + 1] = 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0, nottake = 0;
        if (prev == -1 || g[i] != g[prev])
        {
            take = solve(i + 1, i, g, n) + 1;
        }
        nottake = solve(i + 1, prev, g, n);
        return dp[i][prev + 1] = max(take, nottake);
    }
    void construct(int i, int prev, vector<int> &g, int n, vector<string> &w)
    {
        if (i == n)
            return;
        int take = 0, nottake = 0;
        if (prev == -1 || g[i] != g[prev])
        {
            if (i + 1 == n)
                take = 1;
            else
                take = dp[i + 1][i + 1] + 1;
            // take = solve(i + 1, i, g, n) + 1;
        }
        if (i + 1 == n)
            nottake = 0;
        else
            nottake = dp[i + 1][prev + 1];
        // nottake = solve(i + 1, prev, g, n);
        if (take > nottake)
        {
            ans.push_back(w[i]);
            construct(i + 1, i, g, n, w);
        }
        else
        {
            construct(i + 1, prev, g, n, w);
        }
    }
    vector<string> getLongestSubsequence(vector<string> &w, vector<int> &g)
    {
        memset(dp, -1, sizeof(dp));
        int n = w.size();
        solve(0, -1, g, n);
        construct(0, -1, g, n, w);
        return ans;
    }
};