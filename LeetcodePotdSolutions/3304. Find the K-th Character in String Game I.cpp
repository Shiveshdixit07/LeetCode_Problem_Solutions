class Solution
{
public:
    char kthCharacter(int k)
    {
        string s = "a";
        while (s.length() < k)
        {
            string temp = "";
            for (int i = 0; i < s.length(); i++)
            {
                char c = char(((s[i] - 'a' + 1) % 26) + 97);
                temp += c;
            }
            s += temp;
            if (k - 1 < s.length())
                return s[k - 1];
        }
        return s[k - 1];
    }
};