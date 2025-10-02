class Solution
{
public:
    int maxBottlesDrunk(int n, int e)
    {
        int ans = n;
        while (n >= e)
        {
            ans++;
            n -= e;
            n++;
            e++;
        }
        return ans;
    }
};