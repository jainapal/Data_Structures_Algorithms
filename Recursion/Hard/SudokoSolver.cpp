    void solveSudoku(vector<vector<char> >& board) {
        func(board);
    }
    bool func(vector<vector<char>>& board){
        int n = 9; // size of board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //empty cell found
                if(board[i][j] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(rulesMet(board, i, j, digit)){
                            board[i][j] = digit;
                            if(func(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false; // no digit can be placed
                }
            }
        }
        return true;
    }

    bool rulesMet(vector<vector<char>>& board, int row, int col, char digit){
        for(int i = 0; i < 9 ; i++){
            if(board[row][i] == digit || board[i][col] == digit){
                //digit already in row or col
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == digit){
                    //digit already in 3x3 sub box
                    return false;
                }
            }
        }
        return true;
    }
    TC = O(9 ^ EMPTY CELL), SC = O(EMPTY CELL)