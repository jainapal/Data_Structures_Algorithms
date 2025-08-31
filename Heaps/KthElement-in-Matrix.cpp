1. put all elements of matrix in array, sort it and find kth element. TC = n^2(LOG(n))
2. make min heap for matrix. TC = n^2 + kLOG(n)
3. make min heap for column. TC = n + kLOG(n)
int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<pair<int, pair<int,int>>> temp;
        for(int i = 0; i < mat.size(); i++){
            temp.push_back({mat[i][0],{i,0}});
        }
        // create min heap
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> p(temp.begin(), temp.end());
        
        int ans;
        pair<int, pair<int,int>> element;
        int i, j;
        while(k--){
            element = p.top();
            p.pop();
            ans = element.first; //value
            i = element.second.first; //row
            j = element.second.second; //col
            if(j + 1 < mat.size()){
                p.push({mat[i][j + 1], {i, j + 1}});
            }
        }
        return ans;
    }

4. make min heap and put right and down value in heap. TC = n + kLOG(n)
int kthSmallest(vector<vector<int>> &mat, int k) {
        // create min heap
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> p;
        
        p.push({mat[0][0], {0,0}});
        mat[0][0] = -1;
        int ans = -1;
        pair<int, pair<int,int>> element;
        int i, j;
        while(k--){
            element = p.top();
            p.pop();
            ans = element.first; //value
            i = element.second.first; //row
            j = element.second.second; //col
            if(j + 1 < mat.size() && mat[i][j+1] != -1){
                p.push({mat[i][j + 1], {i, j + 1}});
                mat[i][j+1] = -1;
            }
            if(i + 1 < mat.size() && mat[i+1][j] != -1){
                p.push({mat[i+1][j], {i + 1, j}});
                mat[i + 1][j] = -1;
            }
        }
        return ans;
    }

5. Binary Search TC = O(nLOG(maxValue - minValue)), sc = O(1)
class Solution {
  public:
  
    int countElement(int mid, vector<vector<int>>& mat, int n){
        int cnt = 0;
        int row = n - 1, col = 0;
        while(row >= 0 && col < n){
            if(mat[row][col] <= mid){ //last element of this column
                cnt += row + 1; // all elements in this column till this row
                col++;
            }
            else row--;
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int i = mat[0][0], j = mat[n - 1][n - 1];
        int ans = -1;
        
        while(i <= j){
            int mid = i + (j - i) / 2;
            int cnt = countElement(mid, mat, n);
            if(cnt >= k){
                ans = mid; //mid could be an ans
                j = mid - 1; //check if smaller ans than mid exist 
            }
            else i = mid + 1;
        }
        return ans;
    }
};
