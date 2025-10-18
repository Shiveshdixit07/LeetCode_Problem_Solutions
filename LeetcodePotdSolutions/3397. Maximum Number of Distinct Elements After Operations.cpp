class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int same = 0;
        int prev = -1e9 - 2;
        for (int i = 0; i < n; i++)
        {
            int curr = max(prev + 1, nums[i] - k);
            if (curr > nums[i] + k)
            {
                same++;
            }
            else
            {
                prev = curr;
            }
        }
        return n - same;
    }
};