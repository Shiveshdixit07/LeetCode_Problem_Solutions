class Solution
{
public:
    bool isValid(vector<int> &nums, int t, int n, int p)
    {
        int cnt = 0;
        int idx = 0;
        while (idx < n - 1)
        {
            if (nums[idx + 1] - nums[idx] <= t)
            {
                cnt++;
                if (cnt >= p)
                    return 1;
                idx++;
            }
            idx++;
        }
        return 0;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int h = nums[n - 1] - nums[0];
        if (p == 0)
            return 0;

        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (isValid(nums, mid, n, p))
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};