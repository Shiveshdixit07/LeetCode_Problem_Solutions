class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int n = nums.size();
        int badIdx = -1;
        int f = -1;
        int s = -1;
        for (int i = 0; i < n; i++)
        {
            if (!(minK <= nums[i] && nums[i] <= maxK))
                badIdx = i;
            if (nums[i] == minK)
                f = i;
            if (nums[i] == maxK)
                s = i;
            ans += max(0, min(f, s) - badIdx);
        }
        return ans;
    }
};