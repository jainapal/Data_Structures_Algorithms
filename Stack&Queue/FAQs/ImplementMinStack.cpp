stack<pair<int,int>> st;
public:
    MinStack() {
    }

  void push(int value) { //O(1)
    if(st.empty()){
      st.push({value,value});
    }
    else{
      st.push({value,min(value,st.top().second)});
    }
  }

  void pop() { //O(1)
    st.pop();
  }

  int top() { //O(1)
    return st.top().first;
  }

  int getMin() { //O(1)
    return st.top().second;
  }
  TC = O(1), SC = O(2N);
------------------------------------------------------------------------------------------
class MinStack {
  stack<int> st;
  int MIN;
public:
    MinStack() {
   
    }

  void push(int value) {
    if(st.empty()){
      MIN = value;
      st.push(value);
      return;
    }
    if(value > MIN) st.push(value);
    else{
      st.push(2 * value - MIN);
      MIN = value;
    }
  }

  void pop() {
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    //modified val added to stack
    if(x < MIN){
      MIN = 2 * MIN - x;
    }
  }

  int top() {
    if(st.empty()) return -1;
    int x = st.top();
    if(MIN < x) return x;
    return MIN;
  }

  int getMin() {
    return MIN;
  }
};
TC = O(1), SC = O(N);