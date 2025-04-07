class Solution
{
public:
    int dp[10001][200];
    bool solve(vector<int> &nums, int req, int idx)
    {
        if (req == 0)
            return 1;
        if (req < 0)
            return 0;
        if (idx >= nums.size())
            return 0;

        if (dp[req][idx] != -1)
            return dp[req][idx];
        int t = solve(nums, req - nums[idx], idx + 1);
        int n = solve(nums, req, idx + 1);

        return dp[req][idx] = (t || n);
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return 0;
        int req = (sum >> 1);
        memset(dp, -1, sizeof(dp));
        return solve(nums, req, 0);
    }
};