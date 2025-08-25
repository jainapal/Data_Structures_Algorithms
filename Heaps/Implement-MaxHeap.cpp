class Solution{
    public:

        void initializeHeap(){
            arr.clear();
            count = 0;
        }

        void insert(int key){
            arr.push_back(key);
            heapifyUp(arr,count);
            count++;
            return;
        }

        void changeKey(int index, int new_val){
            if(arr[index] < new_val){
                arr[index] = new_val;
                heapifyUp(arr, index);
            }
            else{
                arr[index] = new_val;
                heapifyDown(arr, index);
            }
            return;
        }

        void extractMax(){
            if(count == 0) return ;
            int ele = arr[0];
            swap(arr[0], arr[count-1]);
            arr.pop_back();
            count--;
            heapifyDown(arr,0);
        }

        bool isEmpty(){
            return (count == 0);
        }

        int getMax(){
            if(count == 0) return -1;
            return arr[0];
        }

        int heapSize(){
            return count;
        }

    private:
        vector<int> arr;
        int count;

        void heapifyUp(vector<int> &arr, int ind){
            int parent = (ind - 1)/2;

            if(ind > 0 && arr[ind] > arr[parent]){
                swap(arr[ind], arr[parent]);
                heapifyUp(arr, parent);
            }
            return;
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
};
TC = O(LOGN), SC = O(N)