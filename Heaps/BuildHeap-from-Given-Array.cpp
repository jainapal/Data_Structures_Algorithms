Given an array of integers nums, convert it in-place into a min-heap.

void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        //iterate backwards on non -leaf nodes
        for(int i = n/2 - 1; i >=0; i--){
            heapifyDown(nums, i);
        }
    }

    void heapifyDown(vector<int> &arr, int ind){
        int n = arr.size();
        int smallestind = ind;
        int leftchild = 2*ind + 1;
        int rightchild = 2*ind + 2;

        if(leftchild < n && arr[leftchild] < arr[smallestind]){
            smallestind = leftchild;
        }
        if(rightchild < n && arr[rightchild] < arr[smallestind]){
            smallestind = rightchild;
        }

        if(smallestind != ind){
            swap(arr[ind] , arr[smallestind]);
            //recursively heapify lower subtrees
            heapifyDown(arr, smallestind);
        }
        return;
    }

    TC = O(N), SC = O(NLOGN)