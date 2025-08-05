struct Node{ //declare structure name Node
    int val; //holds the value in node
    Node* next; //point to next node in list

    Node(int d){ //constructor : initialises node
        val = d; //set value d 
        next = NULL; //sets next as null
    }
};
class LinkedListStack {
private:
    Node* topnode; //top of stack
    int size;
public:
    LinkedListStack() { //constructor 
        topnode = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node *element = new Node(x);
        element->next = topnode;
        topnode = element; //updating top
        size++;
    }
    
    int pop() {
        if(topnode == NULL) return -1;
        int value = topnode->val; //val of top
        Node* temp = topnode; //store top temporarily
        topnode = topnode->next; //update top to next node
        delete temp; //delete old top node
        size--;
        return value;
    }
    
    int top() {
        if(topnode == NULL) return -1;
        return topnode->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};
TC = O(1), SC =O(N) N = no. of nodes 