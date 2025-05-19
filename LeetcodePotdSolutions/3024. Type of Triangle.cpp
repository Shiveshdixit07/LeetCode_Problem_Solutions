class Solution
{
public:
    bool chk(int a, int b, int c) { return a + b <= c; }
    string triangleType(vector<int> &nums)
    {
        if (chk(nums[0], nums[1], nums[2]) || chk(nums[1], nums[2], nums[0]) ||
            chk(nums[2], nums[0], nums[1]))
            return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
            return "isosceles";
        return "scalene";
    }
};