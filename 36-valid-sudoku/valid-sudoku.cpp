class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check for rows
        for (int row = 0; row < 9; row++) {
            set<int> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                int value = board[row][col] - '1';
                if (st.find(value) != st.end())
                    return false;
                st.insert(value);
            }
        }

        // check for cols
        for (int col = 0; col < 9; col++) {
            set<int> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;
                int value = board[row][col] - '1';
                if (st.find(value) != st.end())
                    return false;
                st.insert(value);
            }
        }

        // check for grid (3x3)
        int rs = 0, re = 0, cs = 0, ce = 0;
        for (int row = 0; row < 9; row += 3) {
            rs = row;
            re = row + 2;
            cs = 0;
            ce = 2;

            for (int times = 0; times < 3; times++) {

                set<int> st;
                for (int i = rs; i <= re; i++) {
                    for (int j = cs; j <= ce; j++) {
                        if (board[i][j] == '.')
                            continue;
                        int value = board[i][j] - '1';
                        if (st.find(value) != st.end())
                            return false;
                        st.insert(value);
                    }
                }

                cs += 3;
                ce += 3;
            }
        }

        return true;
    }
};