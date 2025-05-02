class Solution
{
public:
    string pushDominoes(string &d)
    {
        int n = d.length();
        vector<int> LfromRightSide(n, -1);
        int idx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            LfromRightSide[i] = idx;
            if (d[i] == 'L')
                idx = i;
            else if (d[i] == 'R')
                idx = -1;
        }
        int prevR = -1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == '.')
            {
                if (LfromRightSide[i] == -1 && prevR == -1)
                    continue;
                else if (LfromRightSide[i] == -1)
                    d[i] = 'R';
                else if (prevR == -1)
                    d[i] = 'L';
                else if (i - prevR < LfromRightSide[i] - i)
                {
                    d[i] = 'R';
                }
                else if (i - prevR > LfromRightSide[i] - i)
                {
                    d[i] = 'L';
                }
            }
            else if (d[i] == 'R')
                prevR = i;
            else
            {
                prevR = -1;
            }
        }
        return d;
    }
};