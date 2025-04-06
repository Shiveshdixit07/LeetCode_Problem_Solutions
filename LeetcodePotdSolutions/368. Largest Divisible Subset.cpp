class Solution
{
public:
    int dp[1001][1001];
    vector<int> ans;
    int solve(vector<int> &nums, int idx, int prev)
    {
        if (idx >= nums.size())
            return dp[prev + 1][idx] = 0;
        if (dp[prev + 1][idx] != -1)
            return dp[prev + 1][idx];
        int take = 0, nottake = 0;
        if (prev == -1 || nums[idx] % nums[prev] == 0)
        {
            take = solve(nums, idx + 1, idx) + 1;
        }
        nottake = solve(nums, idx + 1, prev);
        return dp[prev + 1][idx] = max(take, nottake);
    }
    void f(vector<int> &nums, int idx, int prev)
    {
        if (idx >= nums.size())
            return;

        int take = 0, nottake = 0;
        if (prev == -1 || nums[idx] % nums[prev] == 0)
        {
            take = dp[idx + 1][idx + 1] + 1;
        }
        nottake = dp[prev + 1][idx + 1];
        if (take > nottake)
        {
            ans.push_back(nums[idx]);
            f(nums, idx + 1, idx);
        }
        else
        {
            f(nums, idx + 1, prev);
        }
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        solve(nums, 0, -1);
        f(nums, 0, -1);
        return ans;
    }
};