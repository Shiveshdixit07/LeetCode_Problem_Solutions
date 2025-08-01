class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < n; i++)
        {
            vector<int> temp = {1};
            for (int j = 1; j < i; j++)
            {
                temp.push_back(ans.back()[j] + ans.back()[j - 1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};