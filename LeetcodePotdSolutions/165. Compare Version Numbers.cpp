class Solution
{
public:
    int compareVersion(string &v1, string &v2)
    {
        int i = 0, j = 0;
        int n1 = v1.length();
        int n2 = v2.length();
        while (i < n1 || j < n2)
        {
            int val1 = 0, val2 = 0;
            while (i < n1 && v1[i] == '0')
            {
                i++;
            }
            while (i < n1 && v1[i] != '.')
            {
                val1 = val1 * 10 + (v1[i] - '0');
                i++;
            }
            while (j < n2 && v2[j] == '0')
            {
                j++;
            }
            while (j < n2 && v2[j] != '.')
            {
                val2 = val2 * 10 + (v2[j] - '0');
                j++;
            }
            if (val1 < val2)
                return -1;
            else if (val1 > val2)
                return 1;
            i++, j++;
        }
        return 0;
    }
};