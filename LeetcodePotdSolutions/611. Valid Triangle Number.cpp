class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int idx =
                    lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) -
                    nums.begin();
                idx--;
                ans += max(0, idx - j);
            }
        }
        return ans;
    }
};