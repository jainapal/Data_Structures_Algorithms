vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights) {
     vector<int> pse = findPSE(heights);
     vector<int> nse = findNSE(heights);
     int n = heights.size();
     int maxarea = 0, area;

     for(int i = 0; i < n; i++){
        area = heights[i] * (nse[i] - pse[i] - 1);
        maxarea = max(maxarea, area);
     }
     return maxarea;
    }
    TC = O(N), SC =O(N + N)
------------------------------------------------------------------------------------------
int largestRectangleArea(vector<int> &heights) {
     int n = heights.size();
     stack<int> st;
     int ans = 0;
     int area, nse, pse;
     for(int i = 0; i < n;i++){ //O(n)
        while(!st.empty() && heights[st.top()] > heights[i]){
            int element = heights[st.top()];
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            area = element * ( nse - pse - 1);
            ans = max(ans, area);
        }
        st.push(i);
     }
     while(!st.empty()){
        nse = n;
        int element = heights[st.top()];
        st.pop();
        pse = st.empty() ? -1 : st.top();
        ans = max(ans, element * (nse - pse - 1));
     }
     return ans;
    }
    TC = O(N + N), SC = O(N)