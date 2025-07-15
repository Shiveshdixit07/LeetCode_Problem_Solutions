class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    bool isValid(string &w)
    {
        int n = w.length();
        if (n < 3)
            return 0;
        int c = 0, v = 0;
        for (int i = 0; i < n; i++)
        {
            if (w[i] == '@' || w[i] == '#' || w[i] == '$')
                return 0;
            if (isVowel(w[i]))
                v++;
            else if (w[i] >= '0' && w[i] <= '9')
            {
                continue;
            }
            else
            {
                c++;
            }
        }

        return (c >= 1 && v >= 1);
    }
};