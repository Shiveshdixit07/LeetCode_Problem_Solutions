class Solution
{
public:
    vector<int> partitionLabels(string &s)
    {
        int n = s.length();
        vector<vector<int>> left(n + 1, vector<int>(26));
        vector<vector<int>> right(n + 1, vector<int>(26));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                right[i][j] = right[i + 1][j];
            }
            right[i][s[i] - 'a']++;
        }
        vector<int> ans;
        int prev = -1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                left[i + 1][j] = left[i][j];
            }
            left[i + 1][s[i] - 'a']++;
            bool f = 0;
            for (int j = 0; j < 26; j++)
            {
                if (left[i + 1][j] && right[i + 1][j])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                ans.push_back(i - prev);
                prev = i;
                for (int j = 0; j < 26; j++)
                {
                    left[i + 1][j] = 0;
                }
            }
        }
        ans.push_back(n - 1 - prev);
        return ans;
    }
};