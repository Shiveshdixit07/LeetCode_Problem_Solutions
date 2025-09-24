class Solution
{
public:
    string fractionToDecimal(int num, int denom)
    {
        if (num == 0)
            return "0";
        string ans = "";
        if (1LL * num * denom < 0)
            ans += "-";
        long long n = abs(1LL * num);
        long long d = abs(1LL * denom);
        long long div = n / d;
        long long r = n % d;
        ans += to_string(div);
        if (r == 0)
            return ans;
        ans += ".";
        unordered_map<int, int> mp;
        while (r != 0)
        {
            if (mp.count(r))
            {
                ans.insert(mp[r], "(");
                ans += ")";
                break;
            }
            mp[r] = ans.length();
            r *= 10;
            div = r / d;
            r = r % d;
            ans += to_string(div);
        }
        return ans;
    }
};