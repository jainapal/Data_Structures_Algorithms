class StackQueue {
    stack<int> s1, s2;
public:
    StackQueue() {
    }
    
    void push(int x) { //O(2N)
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() { //O(1)
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() { //O(1)
        return s1.top();
    }
    
    bool isEmpty() { //O(1)
        return s1.size() == 0;
    }
};
SC + O(2N)
-------------------------------------------------------------------------------
class StackQueue {
    stack<int> s1, s2;
public:
    StackQueue() {
    }
    
    void push(int x) { //O(1)
        s1.push(x);
    }
    
    int pop() { //O(N)
        
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() { O(N)
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        return s2.top();
    }
    
    bool isEmpty() { //O(1)
        return s1.empty() && s2.empty();
    }
};
SC = O(2N);