    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //initialise board with empty cells
        vector<string> board(n, string(n, '.'));

        func(0, ans, board);
        return ans;
    }

    void func(int col, vector<vector<string>>& ans, vector<string>& board){
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < board.size(); row++){
            if(is_safe(board, row, col)){
                board[row][col] = 'Q';
                func(col + 1, ans, board);
                //remove queen and backtrack
                board[row][col] = '.';
            }
        }
    }

    bool is_safe(vector<string>& board, int row, int col){
        int r = row, c = col;
        //check upper left diagonal
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row, c = col;

        //check left side
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }
        r = row, c = col;

        //check lower left diagonal
        while(r < board.size() && c >= 0){
            if(board[r][c] == 'Q') return false;
            r++, c--;
        }

        return true;
    }

    TC = O(N!), SC = O(N)