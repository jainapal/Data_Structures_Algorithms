    void func(int ind, string s,string digits,vector<string>& ans,string combo[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < combo[digit].size();i++){
            s.push_back(combo[digit][i]);
            func(ind + 1, s, digits, ans, combo);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string combo[] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s ="";
        func(0, s, digits, ans, combo);
        return ans;
    }