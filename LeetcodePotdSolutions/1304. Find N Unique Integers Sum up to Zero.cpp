class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;
        int i = 0;
        for (i; i < n / 2; i++)
        {
            ans.push_back(i + 1);
            ans.push_back(-1 * (i + 1));
        }
        if (n & 1)
            ans.push_back(0);
        return ans;
    }
};