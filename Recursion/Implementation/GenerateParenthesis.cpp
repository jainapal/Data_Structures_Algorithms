vector<string> generateParenthesis(int n){
    string s;
    vector<string> ans;
    return func(0, 0, n, s, ans);
}

void func(int open , int close, int n, string s, vector<string>& ans){
    if(open == close && open + close == 2*n){
        ans.push_back(s);
        return;
    }
    if(open < n){
        func(open + 1, close, n, s + '(', ans);
    }
    if(close < open){
        func(open, close + 1, n, s + ')', ans);
    }
}

/* can this problem be solved iteratively instead of recursively??

Instead of recursion maintain a stack of states.
Each state contains:
The current string of parentheses built so far.
The count of open and close parentheses used so far. */

vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        stack<tuple<string, int, int>> st;
        st.push({"", 0, 0});

        while(!st.empty()){
            auto [current, open, close] = st.top();
            st.pop();

            if(current.size() == 2*n){
                ans.push_back(current);
                continue;
            }
            if(open < n){
                st.push({current + '(', open + 1, close});
            }
            if(close < open){
                st.push({current + ')', open, close + 1});
            }
        }
        return ans;
    }

// how would you extend this for other types of brackets (eg, [], {})

void generate(string current, int round_open, int round_close,
              int square_open, int square_close,
              int curly_open, int curly_close,
              string stack, vector<string>& result, int n) {
    
    if (round_open == n && round_close == n &&
        square_open == n && square_close == n &&
        curly_open == n && curly_close == n && stack.empty()) {
        result.push_back(current);
        return;
    }

    if (round_open < n)
        generate(current + "(", round_open + 1, round_close,
                 square_open, square_close, curly_open, curly_close,
                 stack + "(", result, n);

    if (square_open < n)
        generate(current + "[", round_open, round_close,
                 square_open + 1, square_close, curly_open, curly_close,
                 stack + "[", result, n);

    if (curly_open < n)
        generate(current + "{", round_open, round_close,
                 square_open, square_close, curly_open + 1, curly_close,
                 stack + "{", result, n);

    if (!stack.empty()) {
        char last = stack.back();
        if (last == '(' && round_close < round_open)
            generate(current + ")", round_open, round_close + 1,
                     square_open, square_close, curly_open, curly_close,
                     stack.substr(0, stack.size() - 1), result, n);

        if (last == '[' && square_close < square_open)
            generate(current + "]", round_open, round_close,
                     square_open, square_close + 1, curly_open, curly_close,
                     stack.substr(0, stack.size() - 1), result, n);

        if (last == '{' && curly_close < curly_open)
            generate(current + "}", round_open, round_close,
                     square_open, square_close, curly_open, curly_close + 1,
                     stack.substr(0, stack.size() - 1), result, n);
    }
}

vector<string> generateAllBrackets(int n) {
    vector<string> result;
    generate("", 0, 0, 0, 0, 0, 0, "", result, n);
    return result;
}





