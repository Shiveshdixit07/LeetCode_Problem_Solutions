class Solution
{
public:
#define ll long long
    unordered_set<string> st;
    ll fact(ll num)
    {
        ll ans = 1;
        for (int i = 1; i <= num; i++)
        {
            ans *= i;
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k)
    {
        ll d = (n + 1) / 2;
        ll s = pow(10, d - 1);
        ll e = pow(10, d) - 1;

        for (int i = s; i <= e; i++)
        {
            string leftHalf = to_string(i);
            string full = "";
            if (n & 1)
            {
                string rightHalf = leftHalf.substr(0, d - 1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            else
            {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            ll num = stoll(full);
            if (num % k == 0)
            {
                sort(full.begin(), full.end());
                st.insert(full);
            }
        }
        ll ans = 0;
        for (auto e : st)
        {
            vector<int> ht(10);
            for (auto c : e)
            {
                ht[c - '0']++;
            }
            int nonZero = n - ht[0];
            ll denom = 1;
            for (int i = 0; i < 10; i++)
            {
                if (ht[i] > 0)
                {
                    denom *= fact(ht[i]);
                }
            }
            ll numerator = fact(n - 1) * nonZero;
            ans += (numerator / denom);
        }
        return ans;
    }
};