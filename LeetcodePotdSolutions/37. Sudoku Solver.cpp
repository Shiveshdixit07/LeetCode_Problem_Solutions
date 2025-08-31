class Solution
{
public:
    int check(vector<vector<char>> &board, int i, int j, char t)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] == t)
                return 0;
            if (board[k][j] == t)
                return 0;
            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == t)
                return 0;
        }
        return 1;
    }
    int solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (check(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (solve(board))
                            {
                                return 1;
                            }

                            board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    void solveSudoku(vector<vector<char>> &board) { solve(board); }
};