class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums.size();
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k));
        int ans = 0;
        for (int curr = 0; curr < n; curr++)
        {

            for (int prev = 0; prev < curr; prev++)
            {
                int r = (nums[curr] + nums[prev]) % k;
                dp[curr][r] = max(dp[curr][r], (1 + dp[prev][r]));
                ans = max(ans, dp[curr][r] + 1);
            }
        }
        return ans;
    }
};