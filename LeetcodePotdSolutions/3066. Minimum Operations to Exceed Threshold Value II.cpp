class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (int x : nums)
        {
            pq.push(x);
        }
        int ans = 0;
        while (!pq.empty())
        {
            if (pq.size() < 2)
                break;
            long long int x = pq.top();
            pq.pop();

            long long int y = pq.top();
            pq.pop();
            if (x >= k && y >= k)
            {
                break;
            }

            long long int toadd = min(x, y) * 2;
            toadd += max(x, y);
            pq.push(toadd);

            ans++;
        }
        return ans;
    }
};