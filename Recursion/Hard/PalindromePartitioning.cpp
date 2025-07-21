vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> temp;
    func(0,s,temp,ans);
    return ans;
}
void func(int ind, string s, vector<string>& temp, vector<vector<int>>& ans){
    if(ind == s.size()){
        ans.push_back(temp);
        return;
    }
    //check for partition which is palindrome
    for(int i = ind; i < s.size(); i++){
        if(isPalindrome(s, ind, i)){
            temp.push_back(s.substr(ind, i - ind + 1));
            func(ind + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}