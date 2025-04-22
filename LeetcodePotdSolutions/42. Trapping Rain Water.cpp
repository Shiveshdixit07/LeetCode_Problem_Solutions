class Solution
{
public:
    int trap(vector<int> &ht)
    {
        int n = ht.size(), i, ans = 0;
        int left[n], right[n];
        left[0] = ht[0];
        right[n - 1] = ht[n - 1];
        for (i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], ht[i]);
        }
        for (i = n - 2; i >= 0; i--)
        {
            right[i] = max(ht[i], right[i + 1]);
        }
        ans = 0;
        for (i = 1; i < n - 1; i++)
        {
            ans = ans + min(right[i], left[i]) - ht[i];
        }
        return ans;
    }
};