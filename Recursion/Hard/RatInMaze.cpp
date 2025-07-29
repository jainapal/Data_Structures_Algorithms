    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();
        vector<string> ans;
        string s = "";
        if(grid[0][0] == 0 || grid[n-1][n-1] == 0) return ans;
        func(0, 0, ans, s, grid, n);
        return ans;
    }
    void func(int x, int y, vector<string>& ans, string d, vector<vector<int>>& grid, int n){
        if(x == n - 1 && y == n - 1){
            ans.push_back(d);
            return;
        }
        if(grid[x][y] == 0) return; //cell is blocked
        grid[x][y] = 0; //mark cell as visited by setting it to 0

        if(x > 0) func(x-1, y, ans, d + 'U', grid, n);
        if(x < n - 1) func(x + 1, y, ans, d + 'D', grid, n);
        if(y > 0) func(x, y - 1, ans, d + 'L', grid, n);
        if(y < n - 1) func(x, y + 1, ans, d + 'R', grid, n);

        grid[x][y] = 1; //unmark cell as visited by setting it to 1

    }

    TC = 4 ^ (N ^ 2), SC = N^2