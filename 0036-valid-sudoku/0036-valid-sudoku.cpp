class Solution {
public:
    bool isvalid(char ch, int r, int c, vector<vector<char>>& b) {
        int row = b.size();
        int col = b[0].size();

        // checking if there is duplicate of ch in its row
        for (int j = 0; j < col; j++) {

            if (j!=c && b[r][j] == ch) {
                return false;
            }
        }

        // checking if there is duplicate of ch in its col
        for (int i = 0; i < row; i++) {
            if (i!=r && b[i][c] == ch) {
                return false;
            }
        }

        // checking is there is a duplicate in the box
        int boxrow = (r/3)*3;
        int boxcol = (c/3)*3;
        int rowend = boxrow+2;
        int colend = boxcol+2;
        for (int i = boxrow; i <= rowend; i++) {
            for (int j = boxcol; j <=colend; j++) {
                if (i != r && j != c && b[i][j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    continue;
                }
                
                bool ans = isvalid(ch, i, j, board);

                if (ans == false) {
                    return false;
                }
            }
        }

        return true;
    }
};