class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &b)
    {

        for (int i = 0; i < 9; i++)
        {
            unordered_set<int> st;
            int cnt = 0;
            for (int j = 0; j < 9; j++)
            {
                if (b[i][j] != '.')
                {
                    cnt++;
                    st.insert(b[i][j]);
                }
            }
            if (cnt != st.size())
                return 0;
        }
        for (int i = 0; i < 9; i++)
        {
            unordered_set<int> st;
            int cnt = 0;
            for (int j = 0; j < 9; j++)
            {
                if (b[j][i] != '.')
                {
                    cnt++;
                    st.insert(b[j][i]);
                }
            }
            if (cnt != st.size())
                return 0;
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                int cnt = 0;
                unordered_set<int> st;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        if (b[x][y] != '.')
                        {
                            cnt++;
                            st.insert(b[x][y]);
                        }
                    }
                }
                if (cnt != st.size())
                    return 0;
            }
        }
        return 1;
    }
};