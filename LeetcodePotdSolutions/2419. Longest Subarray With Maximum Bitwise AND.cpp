class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];
        int cnt = 1;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == mx)
            {
                cnt++;
            }
            else
            {
                if (nums[i] > mx)
                {
                    mx = nums[i];
                    cnt = 1;
                    ans = 1;
                }
                else
                {
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};