class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long ans = 0;
        ans += 1LL * ((n + 1) / 2) * (m / 2);
        ans += 1LL * ((m + 1) / 2) * (n / 2);
        return ans;
    }
};