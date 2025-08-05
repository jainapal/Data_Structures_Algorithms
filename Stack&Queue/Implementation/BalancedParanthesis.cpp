bool isValid(string str) {
       stack<char> st;
       for(char c : str){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if(!matched(ch, c)) return false;
        }
       }
       return st.empty();
    }
    bool matched(char open , char close){
        if((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}')
        ) return true;

        return false;
    }
    TC = O(N), SC = O(N)