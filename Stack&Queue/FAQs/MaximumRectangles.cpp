int largestRectangleArea(vector<int>& arr){
        int m = arr.size();
        stack<int> st;
        int maxarea = 0;
        int area, pse, nse;
        for(int i = 0; i < m; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int element = arr[st.top()];
                st.pop();
                pse = st.empty() ? -1 : st.top();
                nse = i;
                area = element * (nse - pse -1);
                maxarea = max(maxarea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = m;
            int element = arr[st.top()];
            st.pop();
            pse = st.empty() ? -1 : st.top();
            area = element * (nse - pse - 1);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
       int n = matrix.size();
       int m = matrix[0].size();
       //to store height of different ground levels
       vector<vector<int>> prefixSum(n, vector<int>(m));
       //fill up prefix sum matrix column wise
       for(int j = 0; j < m; j++){ //o(n * m);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += matrix[i][j];
            if(matrix[i][j] == 0){
                prefixSum[i][j] = 0;
                sum = 0;
            }
            prefixSum[i][j] = sum;
        }
       }
       int maxarea = 0;
       //compute over all the rows
       for(int i = 0; i < n; i++){ //o(n)
        //get the largest area of curr level
        int area = largestRectangleArea(prefixSum[i]); //o(2m)
        maxarea = max(maxarea, area);
       }
       return maxarea;
    }
    TC = O(N * M), SC = O(N * M)