class Solution
{
public:
    int grp[46];
    int countLargestGroup(int n)
    {
        int mx = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = i;
            int sum = 0;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            int t = ++grp[sum];
            if (mx < t)
            {
                ans = 1;
                mx = t;
            }
            else if (mx == t)
            {
                ans++;
            }
        }
        return ans;
    }
};