vector<int> nextGreaterElements(vector<int> &arr) {
      int n = arr.size();
      vector<int> ans(n,-1);
      for(int i = 0; i < n; i++){ //n
        int curr = arr[i];
        for(int j = 1; i < n; j++){ //n
          int ind = (i + j) % n;
          if(arr[ind] > arr[i]){
            ans[i] = arr[ind];
            break;
          }
        }
      }
      return ans;
    }
    TC = O(N^2), SC = O(N)
---------------------------------------------------------------------------------------
vector<int> nextGreaterElements(vector<int> &arr) {
      int n = arr.size();
      stack<int> st;
      vector<int> ans(n,-1);
      //traversing double array
      for(int i = 2*n - 1; i >= 0; i--){ //2n
        int curr = arr[i % n];
        while(!st.empty() && st.top() <= curr){ //at max remove 2n
          st.pop();
        }
        if(i < n){
          ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]); //at max push 2n
      }
      return ans;
    }
    TC = O(4N), SC = O(2N)