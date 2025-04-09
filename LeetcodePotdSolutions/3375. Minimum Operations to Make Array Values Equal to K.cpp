class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] < k)
            return -1;
        int x = k;
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == x)
                break;
            if (i == nums.size() - 1 || nums[i] != nums[i + 1])
                ans++;
        }
        return ans;
    }
};