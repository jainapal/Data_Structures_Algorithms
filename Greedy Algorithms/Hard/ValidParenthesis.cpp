bool isValid(string s) {
        int n = s.size();
        return func(s, 0, 0);
    }
    bool func(string& s, int i , int cnt){
        if(cnt < 0) return false;
        if(i == s.size()) return cnt == 0;
        
        if(s[i] == '('){
            return func(s, i + 1, cnt + 1);
        }
        if(s[i] == ')'){
            return func(s, i + 1, cnt - 1);
        }
        if(s[i] == '*'){
            return func(s , i + 1, cnt + 1) ||
            func(s, i + 1, cnt - 1) || func(s, i + 1, cnt);
        }
    }
    TC = (3 ^ k), SC = O(N), K is no. of * characters ... TLE 
    in worst case TC = O(3 ^ N)
-------------------------------------------------------------------------------
Recursion + DP 

unordered_map<int, unordered_map<int, bool>> memo;
    bool isValid(string s) {
        int n = s.size();
        //vector<vector<int>> memo(n, vector<int>(n, -1));
        //return func(s, 0, 0, memo);
        return func(s, 0, 0);
    }
    bool func(string& s, int i , int open){
        if(open < 0) return false;
        if(i == s.size()) return open == 0;

        //if already computed for i,open
        if(memo.count(i) && memo[i].count(open)) return memo[i][open];
        //if(memo[i][open] != -1) return memo[i][open]; if 2d array used

        bool res = false;
        if(s[i] == '('){
            res = func(s, i + 1, open + 1);
        }
        if(s[i] == ')'){
            res = func(s, i + 1, open - 1);
        }
        if(s[i] == '*'){
            res = func(s , i + 1, open + 1) ||
            func(s, i + 1, open - 1) || func(s, i + 1, open);
        }

        //save result to memo table and return it
        return memo[i][open] = res;
        //return memo[i][open] = res; //if 2d array used
    }
    TC = O(N^2) , SC = O(N^2)
     Can also use array instead of map
---------------------------------------------------------------------------------------
bool isValid(string s) {
        int n = s.size();
        int minopen = 0, maxopen = 0;
        for(int it : s){
            if(it == '('){
                minopen++, maxopen++;
            }
            if(it == ')'){
                minopen--, maxopen--;
            }
            if(it == '*'){
                minopen--; //treat as closing
                maxopen++; //treat as open
            }
            if(maxopen < 0) return false;
            if(minopen < 0) minopen = 0;
        }
        return minopen == 0; //if balanced
    }
    TC = O(N), SC =O(1)