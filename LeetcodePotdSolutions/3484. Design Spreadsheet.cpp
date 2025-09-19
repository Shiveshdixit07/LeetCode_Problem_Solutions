class Spreadsheet
{
public:
    vector<vector<int>> vt;
    Spreadsheet(int rows) { vt.assign(rows, vector<int>(26, 0)); }

    void setCell(string cell, int value)
    {
        int c = cell[0] - 'A';
        int idx = 0;
        for (int i = 1; i < cell.length(); i++)
        {
            idx = idx * 10 + cell[i] - '0';
        }
        vt[idx - 1][c] = value;
    }

    void resetCell(string cell) { setCell(cell, 0); }

    int getValue(string f)
    {
        int i = 0;
        i++;
        int v1 = 0, v2 = 0;
        if (f[i] >= 'A' && f[i] <= 'Z')
        {
            int c = f[i++] - 'A';
            int idx = 0;
            for (i; i < f.length() && f[i] != '+'; i++)
            {
                idx = idx * 10 + f[i] - '0';
            }
            v1 = vt[idx - 1][c];
        }
        else
        {
            for (i; i < f.length() && f[i] != '+'; i++)
            {
                v1 = v1 * 10 + f[i] - '0';
            }
        }
        i++;
        if (f[i] >= 'A' && f[i] <= 'Z')
        {
            int c = f[i++] - 'A';
            int idx = 0;
            for (i; i < f.length(); i++)
            {
                idx = idx * 10 + f[i] - '0';
            }
            v2 = vt[idx - 1][c];
        }
        else
        {
            for (i; i < f.length(); i++)
            {
                v2 = v2 * 10 + f[i] - '0';
            }
        }
        return v1 + v2;
    }
};
