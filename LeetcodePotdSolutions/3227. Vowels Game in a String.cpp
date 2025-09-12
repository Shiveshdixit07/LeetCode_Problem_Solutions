class Solution
{
public:
    bool doesAliceWin(string &s)
    {
        for (auto &e : s)
        {
            if (e == 'a' || e == 'i' || e == 'o' || e == 'e' || e == 'u')
                return 1;
        }
        return 0;
    }
};