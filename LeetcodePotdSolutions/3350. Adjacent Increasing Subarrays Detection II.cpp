class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int prev = 0;
        int ans = 0;
        // int t=0;
        for (int i = 0; i < nums.size();)
        {
            int j = i + 1;
            while (j < nums.size() && nums[j] > nums[j - 1])
            {
                j++;
            }
            int nl = j - i;

            ans = max(ans, min(nl, prev));
            ans = max(ans, nl / 2);
            prev = nl;
            i = j;
        }
        return ans;
    }
};