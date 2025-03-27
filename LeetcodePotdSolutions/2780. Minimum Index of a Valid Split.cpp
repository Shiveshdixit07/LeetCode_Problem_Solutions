class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> right, left;
        for (auto i : nums)
            right[i]++;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            left[nums[i]]++;
            right[nums[i]]--;
            if (left[nums[i]] * 2 > (i + 1) && right[nums[i]] * 2 > (n - i - 1))
                return i;
        }
        return -1;
    }
};