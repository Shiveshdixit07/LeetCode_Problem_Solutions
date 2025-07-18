class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int d = nums.size();
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        int n = d / 3;
        vector<long long> p(d), q(d);
        long long sum = 0;
        for (int i = 0; i < d; i++)
        {
            if (maxheap.size() < n)
            {
                sum += nums[i];
                maxheap.push(nums[i]);
            }
            else
            {
                if (maxheap.top() > nums[i])
                {
                    sum -= maxheap.top();
                    maxheap.pop();
                    sum += nums[i];
                    maxheap.push(nums[i]);
                }
            }
            p[i] = sum;
        }
        sum = 0;
        for (int i = d - 1; i >= 0; i--)
        {
            if (minheap.size() < n)
            {
                sum += nums[i];
                minheap.push(nums[i]);
            }
            else
            {
                if (minheap.top() < nums[i])
                {
                    sum -= minheap.top();
                    minheap.pop();
                    sum += nums[i];
                    minheap.push(nums[i]);
                }
            }
            q[i] = sum;
        }

        long long ans = LLONG_MAX;
        for (int i = n - 1; i < (2 * n); i++)
        {
            ans = min(ans, p[i] - q[i + 1]);
        }
        return ans;
    }
};