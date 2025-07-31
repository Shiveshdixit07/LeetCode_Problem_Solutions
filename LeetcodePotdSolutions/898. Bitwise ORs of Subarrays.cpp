class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> curr, prev, res;
        for (int i = 0; i < n; i++)
        {
            for (auto v : prev)
            {
                res.insert(arr[i] | v);
                curr.insert((arr[i] | v));
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return res.size();
    }
};