class Solution
{
public:
    string makeFancyString(string &s)
    {
        string ans = "";
        ans += s[0];
        int cnt = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {

                if (cnt == 2)
                {
                    continue;
                }
                else
                {
                    cnt++;
                    ans += s[i];
                }
            }
            else
            {
                cnt = 1;
                ans += s[i];
            }
        }
        return ans;
    }
};