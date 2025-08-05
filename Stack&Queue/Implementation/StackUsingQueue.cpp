class QueueStack {
    queue<int> q;
public:
    QueueStack() {
    }
    
    void push(int x) { //O(n)
        int s = q.size();
        q.push(x);
        //move elements before new element to back
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() { //O(1)
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() { //O(1)
        return q.front();
    }
    
    bool isEmpty() { //O(1)
        return q.empty();
    }
};
SC = O(n)