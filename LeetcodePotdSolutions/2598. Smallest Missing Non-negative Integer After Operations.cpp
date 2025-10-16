class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        vector<int> ht(nums.size());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int req;
            if (nums[i] < 0)
            {
                req = (nums[i] % value + value) % value;
            }
            else
            {
                req = nums[i] % value;
            }
            if (req < nums.size())
                ht[req]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (ht[i] == 0)
                return i;
            else
            {
                ht[i]--;
                if (ht[i] > 0 && i + value < n)
                {
                    ht[i + value] = ht[i];
                }
            }
        }
        return n;
    }
};