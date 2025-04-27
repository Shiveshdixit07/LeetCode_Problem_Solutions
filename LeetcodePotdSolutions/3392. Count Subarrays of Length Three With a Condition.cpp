class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        if (nums[1] == 2 * (nums[0] + nums[2]))
            ans++;
        for (int i = 3; i < n; i++)
        {
            if ((nums[i] + nums[i - 2]) * 2 == nums[i - 1])
                ans++;
        }
        return ans;
    }
};