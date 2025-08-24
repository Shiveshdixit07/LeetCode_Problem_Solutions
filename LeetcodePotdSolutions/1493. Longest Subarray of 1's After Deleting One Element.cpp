class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int cnt1 = 0, cnt0 = 0, prevCnt1 = 0;
        int ans = 0;
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
            {
                cnt1++;
            }
            else
            {
                if (cnt0 == 1)
                {
                    ans = max(ans, cnt1 + prevCnt1);
                    f = 0;
                }
                prevCnt1 = cnt1;
                cnt1 = 0;
                cnt0 = 1;
            }
            ans = max(ans, cnt1);
        }
        if (cnt1 > 0 && cnt0 == 1)
        {
            ans = max(ans, cnt1 + prevCnt1);
            f = 0;
        }
        return max(ans - f, 0);
    }
};