class Solution
{
public:
    int count(long a, long b, long n)
    {
        int ans = 0;
        while (a <= n)
        {
            ans += b - a;
            a *= 10;
            b *= 10;
            b = min(n + 1, b);
        }
        return ans;
    }
    int findKthNumber(int n, int k)
    {
        k -= 1;
        int curr = 1;
        while (k > 0)
        {
            int ccount = count(curr, curr + 1, n);
            if (ccount <= k)
            {
                k -= ccount;
                curr++;
            }
            else
            {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};