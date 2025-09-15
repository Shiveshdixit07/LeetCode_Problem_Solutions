class Solution
{
public:
    int canBeTypedWords(string &text, string &b)
    {
        int ht[26];
        for (auto c : b)
        {
            ht[c - 'a']++;
        }
        int ans = 0;

        for (int i = 0; i < text.length(); i++)
        {
            bool f = 1;
            while (i < text.length() && text[i] != ' ')
            {
                if (ht[text[i] - 'a'])
                {
                    f = 0;
                }
                i++;
            }
            if (f)
                ans++;
        }
        return ans;
    }
};