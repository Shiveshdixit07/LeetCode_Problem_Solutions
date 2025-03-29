class Solution
{
public:
    int numberOfSubstrings(string &s)
    {
        int n = s.length();
        int ht[3] = {0};
        int i = 0, j = 0;
        int ans = 0;
        for (j; j < n; j++)
        {
            ht[s[j] - 'a']++;
            while (i <= j && ht[0] > 0 && ht[1] > 0 && ht[2] > 0)
            {
                ans += (n - j);
                ht[s[i] - 'a']--;
                i++;
            }
        }
        return ans;
    }
};