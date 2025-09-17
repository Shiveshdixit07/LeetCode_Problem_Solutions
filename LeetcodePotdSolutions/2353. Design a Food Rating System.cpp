struct cmp
{
    bool operator()(pair<int, string> a, pair<int, string> b) const
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class FoodRatings
{
public:
    unordered_map<string, pair<int, string>> mp1;
    unordered_map<string, set<pair<int, string>, cmp>> mp2;
    FoodRatings(vector<string> &foods, vector<string> &cuisines,
                vector<int> &r)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            mp1[foods[i]] = {r[i], cuisines[i]};
            mp2[cuisines[i]].insert(make_pair(r[i], foods[i]));
        }
    }

    void changeRating(string food, int nr)
    {
        auto [r, c] = mp1[food];
        mp2[c].erase({r, food});
        mp1[food].first = nr;
        mp2[c].insert({nr, food});
    }

    string highestRated(string c)
    {
        auto t = *mp2[c].begin();
        return t.second;
    }
};
