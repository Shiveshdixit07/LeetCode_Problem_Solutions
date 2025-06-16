class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size();
        int mini = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != mini)
                ans = max(ans, nums[i] - mini);
            mini = min(mini, nums[i]);
        }
        return ans;
    }
};