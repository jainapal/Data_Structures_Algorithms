class Solution{
    public:

        void initializeHeap(){
            arr.clear();
            count = 0;
        }

        void insert(int key){ //TC = LOGN
            arr.push_back(key);
            heapifyUp(arr, count);
            count++;
            return ;
        }

        void changeKey(int index, int new_val){ //TC = LOGN
            if(arr[index] > new_val){
                arr[index] = new_val;
                heapifyUp(arr,index);
            }
            else{
                arr[index] = new_val;
                heapifyDown(arr, index);
            }
            return;
        }

        void extractMin(){ //TC = LOGN
            int ele = arr[0]; //min val in heap
            //swap top value with value at last index
            swap(arr[0], arr[count-1]);
            //pop min value from list
            arr.pop_back();
            count --;

            heapifyDown(arr, 0);

        }

        bool isEmpty(){ //TC = 1
            return (count == 0);
        }

        int getMin(){ //TC = I
            return arr[0];
        }

        int heapSize(){ //TC = 1
            return count;
        }
    
    private:
        vector<int> arr; //to store min heap
        int count; //to store the count of elements

        void heapifyDown(vector<int> &arr, int ind){
            int n = arr.size();
            int smallest = ind;
            int left = 2*ind + 1, right = 2*ind + 2;

            if(left < n && arr[left] < arr[smallest]) smallest = left;
            if(right < n && arr[right] < arr[smallest]) smallest = right;

            if(smallest != ind){
                swap(arr[ind] , arr[smallest]);
                heapifyDown(arr, smallest);
            }
            return;
        }
        void heapifyUp(vector<int> &arr, int ind){
            int parent = (ind - 1) / 2;
            if(ind > 0 && arr[ind] < arr[parent]){
                swap(arr[ind] , arr[parent]);
                heapifyUp(arr, parent);
            }
            return;
        }
};

TC =O(LOGN), SC = O(N)