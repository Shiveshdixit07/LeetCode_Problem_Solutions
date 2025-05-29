class Solution
{
public:
    int dp[366][4];
    int solve(vector<int> &d, vector<int> &c, int dur, int idx)
    {
        if (idx >= d.size())
            return 0;
        if (dp[idx][dur + 1] != -1)
        {
            return dp[idx][dur + 1];
        }
        int op1, op2, op3;
        op1 = solve(d, c, 0, idx + 1) + c[0];
        int sidx = lower_bound(d.begin() + idx, d.end(), d[idx] + 7) - d.begin();
        op2 = solve(d, c, 1, sidx) + c[1];
        int tidx = lower_bound(d.begin() + idx, d.end(), d[idx] + 30) - d.begin();
        op3 = solve(d, c, 2, tidx) + c[2];
        return dp[idx][dur + 1] = min({op1, op2, op3});
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, -1, 0);
    }
};