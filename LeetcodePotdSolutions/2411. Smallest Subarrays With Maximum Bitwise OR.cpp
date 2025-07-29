class Solution
{
public:
    int bits[32];
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int mx = 1;
            for (int j = 0; j < 32; j++)
            {
                if (nums[i] & (1 << j))
                    bits[j] = i;
                else if (bits[j] > i)
                    mx = max(mx, bits[j] - i + 1);
            }
            ans[i] = mx;
        }

        return ans;
    }
};