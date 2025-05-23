class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k,
                              vector<vector<int>> &edges)
    {
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> temp;
        for (auto it : nums)
        {
            temp.push_back((it ^ k) - it);
        }

        sort(temp.rbegin(), temp.rend());

        for (int i = 0; i < nums.size(); i += 2)
        {
            if (i == nums.size() - 1)
            {
                break;
            }
            int p = temp[i] + temp[i + 1];
            if (p <= 0)
            {
                break;
            }
            res += p;
        }

        return res;
    }
};