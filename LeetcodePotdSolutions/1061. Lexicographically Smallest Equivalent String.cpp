class Solution
{
public:
    string smallestEquivalentString(string &s1, string &s2, string &base)
    {
        int n = s1.length();
        vector<int> vt(26, -1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            if (vt[a] == -1 && vt[b] == -1)
            {
                cnt++;
                vt[a] = cnt;
                vt[b] = cnt;
            }
            else
            {
                cnt++;
                for (int j = 0; j < 26; j++)
                {
                    if (j != a && vt[a] != -1 && vt[j] == vt[a])
                    {
                        vt[j] = cnt;
                    }
                    else if (j != b && vt[b] != -1 && vt[j] == vt[b])
                    {
                        vt[j] = cnt;
                    }
                }

                vt[a] = cnt;
                vt[b] = cnt;
            }
        }
        string ans = "";
        for (int i = 0; i < base.length(); i++)
        {
            int val = vt[base[i] - 'a'];
            int res = base[i] - 'a';
            if (val == -1)
            {
                ans += base[i];
                continue;
            }
            for (int j = 0; j < 26; j++)
            {
                if (vt[j] == val)
                {
                    res = j;
                    break;
                }
            }
            ans += (res + 'a');
        }

        return ans;
    }
};