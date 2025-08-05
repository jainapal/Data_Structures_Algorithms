class ArrayQueue {
private:
    int* arr;
    int start, end;
    int currsize, maxsize;

public:
    ArrayQueue() {
        arr = new int[10];
        start = -1, end = -1;
        currsize = 0, maxsize = 10;
    }
    
    void push(int x) {
        if(currsize == maxsize) return;
        if(end == -1){
            start = 0, end = 0;
        }
        else{
            end = (end + 1) % maxsize;
        }
        arr[end] = x;
        currsize++;
    }
    
    int pop() {
        if(start == -1) return -1;
        int val = arr[start];
        if(currsize == 1){
            start = -1, end = -1;
        }
        else{
            start = (start + 1) % maxsize;
        }
        currsize--;
        return val;
    }
    
    int peek() {
        if(start == -1) return -1;
        return arr[start];
    }
    
    bool isEmpty() {
        return currsize == 0;
    }
};
TC = O(1) , SC = O(maxsize)