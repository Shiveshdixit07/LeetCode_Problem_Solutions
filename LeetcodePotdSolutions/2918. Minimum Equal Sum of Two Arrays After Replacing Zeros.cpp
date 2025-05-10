class Solution
{
public:
#define ll long long
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        ll m1 = 0, m2 = 0;
        ll c1 = 0, c2 = 0;
        for (auto &e : nums1)
        {
            if (e == 0)
                c1++;
            else
                m1 += e;
        }
        for (auto &e : nums2)
        {
            if (e == 0)
                c2++;
            else
                m2 += e;
        }
        ll ans = 0;
        if (m1 > m2)
        {
            if (m1 + c1 >= m2 + c2)
            {
                if (c2 == 0)
                    return -1;
                ans = m1 + c1;
            }
            else if (c1 == 0)
            {
                return -1;
            }
            else
            {

                ans = m2 + c2;
            }
        }
        else if (m2 > m1)
        {
            if (m2 + c2 >= m1 + c1)
            {
                if (c1 == 0)
                    return -1;
                ans = m2 + c2;
            }
            else if (c2 == 0)
            {
                return -1;
            }
            else
            {
                ans = m1 + c1;
            }
        }
        else
        {
            if ((c1 == 0 && c2 == 0) || (c1 > 0 && c2 > 0))
                ans = m1 + max(c1, c2);
            else
                return -1;
        }
        return ans;
    }
};