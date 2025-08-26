vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(nums,i);
        }
        return nums;
    }
    void heapifyDown(vector<int> &arr, int ind){
        int n = arr.size();
        int largest = ind;
        int left = 2*ind + 1, right = 2*ind + 2;

        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;

        if(largest != ind){
            swap(arr[ind], arr[largest]);
            heapifyDown(arr, largest);
        }
        return;
    }
    
    TC  = O(N), SC = O(LOGN)