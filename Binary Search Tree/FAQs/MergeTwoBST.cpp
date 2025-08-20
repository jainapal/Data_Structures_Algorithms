void inorder(Node* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        
        vector<int> ans;
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] <= v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        
        while(i < v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j < v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
    TC = O(N + M), SC = O(N + M)
-----------------------------------------------------------------------
Iterative Approach

vector<int> merge(Node *root1, Node *root2) {
        stack<Node*> s1, s2;
        while(root1){ //push left elements in stack
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2){ 
            s2.push(root2);
            root2 = root2->left;
        }
        
        vector<int> ans;
        while(!s1.empty() && !s2.empty()){
            if(s1.top()->data < s2.top()->data){
                ans.push_back(s1.top()->data);
                Node* temp = s1.top()->right;
                s1.pop();
                while(temp){
                    s1.push(temp);
                    temp = temp->left;
                }
            }
            else if(s1.top()->data > s2.top()->data){
                ans.push_back(s2.top()->data);
                Node* temp = s2.top()->right;
                s2.pop();
                while(temp){
                    s2.push(temp);
                    temp = temp->left;
                }
            }
            else{
                ans.push_back(s1.top()->data);
                ans.push_back(s2.top()->data);
                Node* temp1 = s1.top()->right;
                Node* temp2 = s2.top()->right;
                s1.pop(), s2.pop();
                while(temp1){
                    s1.push(temp1);
                    temp1 = temp1->left;
                }
                while(temp2){
                    s2.push(temp2);
                    temp2 = temp2->left;
                }
            }
        }
        // Cleanup remaining nodes from s1
        while(!s1.empty()){
            ans.push_back(s1.top()->data);
            Node* curr = s1.top()->right;
            s1.pop();
            while(curr){
                s1.push(curr);
                curr = curr->left;
            }
        }
        // Cleanup remaining nodes from s2
        while(!s2.empty()){
            ans.push_back(s2.top()->data);
            Node* curr = s2.top()->right;
            s2.pop();
            while(curr){
                s2.push(curr);
                curr = curr->left;
            }
        }
        return ans;
    }
    TC =O(N), SC = O(N)