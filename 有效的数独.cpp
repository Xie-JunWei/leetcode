class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10];
        bool col[9][10];
        bool box[9][10];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                row[i][j] = false;
                col[i][j] = false;
                box[i][j] = false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    int boxindex = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || box[boxindex][num])
                    {
                        return false;
                    }
                    else
                    {
                        row[i][num] = true;
                        col[j][num] = true;
                        box[boxindex][num] = true;
                    }
                }

            }
        }
        return true;
    }
};