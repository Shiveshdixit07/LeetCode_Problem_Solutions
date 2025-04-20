class Solution
{
public:
    int numRabbits(vector<int> &ans)
    {
        unordered_map<int, int> mp;
        int result = 0;
        for (int i = 0; i < ans.size(); i++)
            mp[ans[i]]++;
        for (auto it : mp)
        {
            int num = it.first;
            int freq = it.second;
            int total = num + 1;
            int temp = ceil(freq / (1.0 * total));
            result += temp * total;
        }
        return result;
    }
};