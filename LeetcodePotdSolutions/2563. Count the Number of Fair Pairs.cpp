class Solution
{
public:
#define ll long long
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = lower - nums[i];
            int idx = lower_bound(nums.begin() + i + 1, nums.end(), left) -
                      nums.begin();
            if (idx >= n)
                continue;
            int right = upper - nums[i];
            int idx2 = upper_bound(nums.begin() + i + 1, nums.end(), right) -
                       nums.begin();
            ans += (idx2 - idx);
        }
        return ans;
    }
};