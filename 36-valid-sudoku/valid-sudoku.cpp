class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &a)
        {

            int rows[9][9] = { 0 };
            int cols[9][9] = { 0 };
            int grids[9][9] = { 0 };

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (a[i][j] != '.')
                    {

                        int curr = a[i][j] - '1';
                        int k = (i / 3) * 3 + (j / 3);

                        if (rows[i][curr] || cols[j][curr] || grids[k][curr]) return false;

                        rows[i][curr]++;
                        cols[j][curr]++;
                        grids[k][curr]++;
                    }
                }
            }

            return true;
        }
};