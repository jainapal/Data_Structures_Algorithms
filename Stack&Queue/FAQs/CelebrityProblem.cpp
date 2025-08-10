int celebrity(vector<vector<int>> &M){
        vector<int> knows(M.size(), 0);
        vector<int> knownBy(M.size(), 0);
        for(int i= 0; i < M.size(); i++){
            for(int j = 0; j < M.size(); j++){
                if(M[i][j] == 1){
                    knows[i]++; //i knows j
                    knownBy[j]++; //j known by i
                }
            }
        }
        for(int i = 0; i < M.size(); i++){
            if(knows[i] == 0 && knownBy[i] == M.size() - 1){
                return i;
            }
        }
        return -1;
    }
    TC = O(N^2 + N), SC = O(2N)
-------------------------------------------------------------------------------
int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0, bottom = n - 1;
        while(top < bottom){
            //top knows bottom, cant be celebrity
            if(M[top][bottom] == 1) top++;
            //bottom knows top, cant be celebrity
            else if(M[bottom][top] == 1) bottom--;
            //both cant be celebrity
            else{
                top++;
                bottom--;
            }
        }
        if(top > bottom) return -1;
        for(int i = 0; i < n; i++){
            if(i == top) continue;
            if(M[top][i] == 1 || M[i][top] == 0){
                return -1;
            }
        }
        return top;
    }
    TC = O(N + N), SC = O(1)