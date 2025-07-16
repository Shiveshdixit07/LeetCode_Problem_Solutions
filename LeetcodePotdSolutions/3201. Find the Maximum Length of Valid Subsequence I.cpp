class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size();
        int e = 0, o = 0;
        for (auto &x : nums)
        {
            if (x & 1)
                o++;
            else
                e++;
        }
        int ans = max(e, o);
        e = 0, o = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
            {
                o = e + 1;
            }
            else
            {
                e = o + 1;
            }
        }
        ans = max(ans, max(e, o));
        return ans;
    }
};