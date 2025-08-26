class Solution {
public:
    void heapSort(vector<int>&arr) {
        buildMaxHeap(arr);
        int last = arr.size() - 1;
        while(last > 0){ //o(n)
            swap(arr[0], arr[last]);
            last--;
            if(last > 0) heapifyDown(arr,0,last); //o(logn)
        }
        return;
    }
    void heapifyDown(vector<int> &arr, int ind, int last){
        int largest = ind;
        int left = 2*ind + 1, right = 2*ind + 2;

        if(left <= last && arr[left] > arr[largest]) largest = left;
        if(right <= last && arr[right] > arr[largest]) largest = right;
        if(largest != ind){
            swap(arr[ind], arr[largest]);
            heapifyDown(arr, largest, last);
        }
        return;
    }
    void buildMaxHeap(vector<int> &arr){
        int n = arr.size();
        for(int i = n/2 - 1; i >=0; i--){
            heapifyDown(arr, i, n-1);
        }
        return;
    }
};
TC = O(NLOG(N)), SC = O(LOGN)