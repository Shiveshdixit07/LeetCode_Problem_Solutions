class MovieRentingSystem
{
public:
    unordered_map<int, set<pair<int, int>>> mpp, mp1, r1;
    set<tuple<int, int, int>> st;
    MovieRentingSystem(int n, vector<vector<int>> &e)
    {
        for (auto x : e)
        {
            int shop = x[0];
            int movie = x[1];
            int price = x[2];
            mpp[movie].insert({price, shop});
            mp1[shop].insert({movie, price});
        }
    }

    vector<int> search(int m)
    {
        vector<int> ans;
        for (auto [p, s] : mpp[m])
        {
            ans.push_back(s);
            if (ans.size() == 5)
                break;
        }
        return ans;
    }

    void rent(int s, int m)
    {
        auto it1 = mp1[s].lower_bound({m, 0});
        mpp[m].erase({it1->second, s});
        r1[s].insert({m, it1->second});
        st.insert({it1->second, s, m});
        mp1[s].erase(it1);
    }

    void drop(int s, int m)
    {
        auto it1 = r1[s].lower_bound({m, 0});
        mp1[s].insert({m, it1->second});
        mpp[m].insert({it1->second, s});
        st.erase({it1->second, s, m});
        r1[s].erase(it1);
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        for (auto [p, s, m] : st)
        {
            ans.push_back({s, m});
            if (ans.size() == 5)
                break;
        }
        return ans;
    }
};
