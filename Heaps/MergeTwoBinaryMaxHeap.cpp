void heapify(vector<int>& ans, int ind, int n){
       int largest = ind;
       int left = 2*ind + 1;
       int right = 2* ind + 2;
       if(left < n && ans[left] > ans[largest]) largest = left;
       if(right < n && ans[right] > ans[largest]) largest = right;
       if(largest != ind){
           swap(ans[largest], ans[ind]);
           heapify(ans, largest, n);
       }
   }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(a[i]);
        for(int i = 0; i < m; i++) ans.push_back(b[i]);
        //convert array into max heap
        n = ans.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(ans, i, n);
        }
        return ans;
    }
    TC = O(N + M)