Given an array nums representing a min-heap and two integers ind and val, 
set the value at index ind (0-based) to val and perform the heapify algorithm 
such that the resulting array follows the min-heap property.
Modify the original array in-place, no need to return anything.

class Solution {
public:
    void heapifyDown(vector<int>& arr, int ind){
        int largest = ind;
        int lchild = 2 * ind + 1;
        int rchild = 2 * ind + 2;
        if(lchild < arr.size() && arr[lchild] < arr[largest]){
            largest = lchild;
        }
        if(rchild < arr.size() && arr[rchild] < arr[largest]){
            largest = rchild;
        }
        if(largest != ind){
            swap(arr[ind], arr[largest]);
            heapifyDown(arr, largest);
        }
    }
    void heapifyUp(vector<int>& arr, int ind){
        int parent = (ind - 1) / 2;
        if(ind > 0){
            if(arr[ind] < arr[parent]){
                swap(arr[ind], arr[parent]);
                heapifyUp(arr, parent);
            }
        }
    }
    void heapify(vector<int> &nums, int ind, int val) {
        if(nums[ind] > val){
            nums[ind] = val;
            heapifyUp(nums, ind);
        }
        else{
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
    }
};
TC = O(Log(N)), SC + O(Log(N))