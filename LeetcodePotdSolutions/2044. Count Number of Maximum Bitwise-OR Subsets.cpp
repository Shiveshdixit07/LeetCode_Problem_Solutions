class Solution
{
public:
    int solve(int idx, vector<int> &nums, int Or, int mx)
    {
        if (idx == nums.size())
        {
            if (Or == mx)
                return 1;
            return 0;
        }

        int a = solve(idx + 1, nums, Or | nums[idx], mx);
        int b = solve(idx + 1, nums, Or, mx);
        return a + b;
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int mx = 0;
        for (auto &e : nums)
            mx |= e;

        return solve(0, nums, 0, mx);
    }
};