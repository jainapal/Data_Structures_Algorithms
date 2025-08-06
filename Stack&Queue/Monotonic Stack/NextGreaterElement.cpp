vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n - 1; i++) {
            int curr = arr[i];
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > curr) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
    TC = O(N^2), SC = O(1)
------------------------------------------------------------------------
vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
       
        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            while(!st.empty() && st.top() <= curr){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();

            st.push(curr);
        }
        return ans;
    }
    TC = O(N), SC = O(N)