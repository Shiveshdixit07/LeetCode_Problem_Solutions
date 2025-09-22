class Solution
{
public:
    int ele[101];
    int maxFrequencyElements(vector<int> &nums)
    {
        int mx = 0;
        for (int x : nums)
        {
            ele[x]++;
            mx = max(mx, ele[x]);
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (ele[i] == mx)
                ans += mx;
        }
        return ans;
    }
};