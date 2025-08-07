string removeKdigits(string nums, int k) {
      int n = nums.size();
      stack<char> st;
      for(int i = 0; i < n; i++){ //o(n)
        while(!st.empty() && k > 0 && nums[i] < st.top()){
          st.pop();
          k--;
        }
        st.push(nums[i]);
      }
      while(!st.empty() && k > 0){ //O(k) worst case
        st.pop();
        k--;
      }
      if(st.empty()) return "0";
      string ans = "";
      while(!st.empty()){ //O(n) worst case
        ans += st.top();
        st.pop():
      }
      //remove zeroes from start
      //trailing zero + reverse take O(n)
      while(ans.size() != 0 && ans.back() == '0'){ //O(n) if have all zeroes
        ans.pop_back();
      }
      if(ans.empty()) return "0";
      //reverse as stack gives in reverse order
      reverse(ans.begin(), ans.end());

      return ans;
    }
    TC = O(3N + K), SC = O(N);