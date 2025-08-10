class Solution
{
public:
    string sortDigit(int n)
    {
        string t = to_string(n);
        sort(t.begin(), t.end());
        return t;
    }
    bool reorderedPowerOf2(int n)
    {
        string orig = sortDigit(n);
        for (int i = 0; i < 32; i++)
        {
            if (sortDigit(1 << i) == orig)
                return 1;
        }
        return 0;
    }
};