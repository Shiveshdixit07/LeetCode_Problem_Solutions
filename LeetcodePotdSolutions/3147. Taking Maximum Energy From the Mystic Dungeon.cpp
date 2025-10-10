class Solution
{
public:
    int dp[100001];
    int solve(int i, vector<int> &e, int k)
    {
        if (i >= e.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = e[i] + solve(i + k, e, k);
    }
    int maximumEnergy(vector<int> &e, int k)
    {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for (int i = 0; i < e.size(); i++)
        {
            ans = max(ans, solve(i, e, k));
        }
        return ans;
    }
};