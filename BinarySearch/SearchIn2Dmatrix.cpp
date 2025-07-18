/*
TC = O(LOG(M*N)), SC = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col

        //finding row in which target should be present
        int top= 0, bottom = m - 1;
        int row = -1;
        while(top <= bottom){
            int mid = top + (bottom - top)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]) bottom = mid - 1;
            else top = mid + 1;
        }

        if( row == -1) return false;
        //search in row
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
 */