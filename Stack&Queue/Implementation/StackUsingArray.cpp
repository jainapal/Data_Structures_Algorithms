class ArrayStack {
private:
    int* arr; //array to hold elements
    int capacity; // max capacity
    int topInd; //index of top

public:
    ArrayStack(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        topInd = -1;
    }
    ~ArrayStack(){ //destructor called when object is destroyed
        delete[] arr; //deallocate memory 
    }
    void push(int x) { //O(1)
        if(topInd >= capacity - 1) return;
        topInd = topInd + 1;
        arr[topInd] = x;
    }
    
    int pop() { //O(1)
        if(topInd == -1) return -1;
        int val = arr[topInd];
        topInd = topInd -1;
        return val;
        
    }
    
    int top() { //O(1)
        if(topInd == -1) return -1;
        return arr[topInd];
    }
    
    bool isEmpty() { //O(1)
        return (topInd == -1);
    }
};
SC = O(capacity)