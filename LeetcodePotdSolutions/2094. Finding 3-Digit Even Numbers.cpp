class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &d)
    {
        vector<int> temp(10, 0);
        for (int digit : d)
            ++temp[digit];

        vector<int> ans;
        for (int i = 100; i < 1000; i += 2)
        {
            int d1 = i / 100, d2 = (i % 100) / 10, d3 = i % 10;
            temp[d1]--;
            temp[d2]--;
            temp[d3]--;
            if (temp[d1] >= 0 && temp[d2] >= 0 && temp[d3] >= 0)
                ans.push_back(i);
            temp[d1]++;
            temp[d2]++;
            temp[d3]++;
        }

        return ans;
    }
};