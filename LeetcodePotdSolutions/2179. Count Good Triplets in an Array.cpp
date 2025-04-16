class Solution
{
public:
#define ll long long
    unordered_map<int, int> mp;
    void updateSTree(int currIdx, int updateIdx, int s, int e,
                     vector<int> &sTree, int value)
    {
        if (updateIdx < s || updateIdx > e)
            return;
        if (s == e && e == updateIdx)
        {
            sTree[currIdx] = value;
            return;
        }
        int mid = s + (e - s) / 2;
        updateSTree(2 * currIdx + 1, updateIdx, s, mid, sTree, value);
        updateSTree(2 * currIdx + 2, updateIdx, mid + 1, e, sTree, value);
        sTree[currIdx] = sTree[2 * currIdx + 1] + sTree[2 * currIdx + 2];
        return;
    }
    long long rangeSum(int qStart, int qEnd, int idx, int s, int e,
                       vector<int> &sTree)
    {
        if (qEnd < s || qStart > e)
            return 0;
        if (qStart <= s && qEnd >= e)
            return sTree[idx];
        int mid = s + (e - s) / 2;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        ll leftSum = rangeSum(qStart, qEnd, leftChild, s, mid, sTree);
        ll rightSum = rangeSum(qStart, qEnd, rightChild, mid + 1, e, sTree);
        return 0LL + leftSum + rightSum;
    }
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> sTree(4 * n + 1, 0);
        for (int i = 0; i < n; i++)
            mp[nums2[i]] = i;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int nums2Idx = mp[nums1[i]];
            updateSTree(0, nums2Idx, 0, n - 1, sTree, 1);
            if (i == 0)
            {
                continue;
            }
            int leftCommanElements =
                rangeSum(0, nums2Idx - 1, 0, 0, n - 1, sTree);
            int leftUncommanElements = i - leftCommanElements;
            int nums2RightElemnts = n - nums2Idx - 1;
            int rightCommanElements = nums2RightElemnts - leftUncommanElements;
            ll temp = 1LL * leftCommanElements * rightCommanElements;
            ans += temp;
        }
        return ans;
    }
};