    bool exist(vector<vector<char> >& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                //first char matches then start search
                if(board[i][j] == word[0]){
                    if(func(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
    bool func(vector<vector<char>>& v, int i, int j, string& s, int ind){
        if(ind == s.size()) return true; // all char found
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || s[ind] != v[i][j]){
            return false;
        }

        bool ans = false;
        char x = v[i][j];
        v[i][j] = ' '; //temporarily mark cell as visited
        //check all possible directions
        ans |= func(v, i + 1, j, s, ind + 1);
        ans |= func(v, i - 1, j, s, ind + 1);
        ans |= func(v, i, j - 1, s, ind + 1);
        ans |= func(v, i, j + 1, s, ind + 1);

        v[i][j] = x; //restore original char

        return ans;
    }

    TC = O( N * M * 4 ^ Word len), SC = O(word len)