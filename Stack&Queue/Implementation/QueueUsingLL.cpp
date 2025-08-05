struct Node{
    Node* next;
    int val;
    Node(int d){
        val = d;
        next = NULL;
    }
};
class LinkedListQueue {
private:
    Node* start;
    Node* end;
    int size;
public:
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node *element = new Node(x);
        if(start == NULL){ //first element is pushed
            start = end = element;
        }
        else{
            end->next = element;
            end = element;
        }
        size++;
    }
    
    int pop() {
        if(start == NULL) return -1; //queue is empty

        int value = start->val;
        Node* temp = start;
        start = start -> next;
        delete temp;
        size--;
        return value;
    }
    
    int peek() {
        if(start == NULL) return -1;
        return start->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};
TC = O(1), SC =O(N), N is no. of nodes