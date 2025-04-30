class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int digits = log10(nums[i]) + 1;
            bool f = (digits & 1);
            ans += (1 - f);
        }
        return ans;
    }
};