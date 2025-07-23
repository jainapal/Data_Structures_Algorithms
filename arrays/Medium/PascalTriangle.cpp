// --> row and col is given , find elemet at that row and col
// int pascalTriangleI(int r, int c) {
//         //element in r row and c col will be (r-1)C(c-1)
//         // that is (r-1)!/(r! * (c-1)!)

//         return nCr(r-1, c-1);
//     }
//     int nCr(int n , int r){
//         if(r > n-r) r = n - r;
//         if(r == 1) return n;
//         int ans = 1;
//         for(int i = 0; i < r; i++){
//             ans *= (n - i);
//             ans /= (i+1);
//         }
//         return ans;
//     }
//     TC = O(COL), SC = O(1);
----------------------------------------------------------------
// -->row is given , find all the values in row
// // if we find every element of row using above method then TC = n^2
// //We need to identify patten in a row to find in optimise way
// vector<int> pascalTriangleII(int r) {
//         //we observe eevry row has same num of elements as row number
//         // element = (prev ele *(r-i)) / i
//         vector<int> ans(r);
//         ans[0] = 1;
//         for(int i = 1; i < r; i++){
//             ans[i] = (ans[i-1]*(r-i))/i;
//         }
//         return ans;
//     }
// };
// TC = O(N), SC = O(1)

----------------------------------------------------------------------------------------------------------
// --> now n is given, find first n rows of pascal triangle
// vector<int> genRow(int row){
//         long long prev = 1;
//         vector<int> rowElements;
//         rowElements.push_back(1);
//         for(int col = 1; col < row; col++){
//             prev = prev * (row - col);
//             prev = prev / col;
//             rowElements.push_back(prev);
//         }
//         return rowElements;
//     }
//     vector<vector<int>> pascalTriangleIII(int numRows) {
//         vector<vector<int>> ans;
//         for(int i = 1; i <= numRows; i++){
//             ans.push_back(genRow(i));
//         }
//         return ans;
//     }
//     TC = O(N^2), SC = O(N^2);