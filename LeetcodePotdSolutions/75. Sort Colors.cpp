class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        for (int i = 0; i <= h; i)
        {
            if (nums[i] == 0)
                swap(nums[l++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[h--]);
            else
                i++;
        }
    }
};