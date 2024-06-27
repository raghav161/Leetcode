class Solution {
public:
    vector<vector<string>> result;
    void solve(vector<string>& board, int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antiDiags) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        for(int col = 0; col<board.size(); col++) {
            int diag_id       = row-col;
            int anti_diag_id  = row+col;
            if(cols.find(col) != cols.end() ||
              diags.find(diag_id) != diags.end() ||
              antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            solve(board, row+1, cols, diags, antiDiags);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        //For, n = 3, board = {"...", "...", "..."} initially
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antiDiags;
        solve(board, 0, cols, diags, antiDiags);
        
        return result;
    }
};