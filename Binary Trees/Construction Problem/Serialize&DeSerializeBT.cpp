class Solution {
public:

    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) ans.append("#,");
            else ans.append(to_string(temp->data) + ',');
            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data); //to tokenize the serialized data
        string str;
        getline(s, str, ','); //read root value from serialized data

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            //read value of left child from serializze data
            getline(s, str, ',');
            if(str != "#"){
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            else node->left = NULL;
            //read value of right child from serialized data
            getline(s, str, ',');
            if(str !="#"){
                TreeNode* rightnode =new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
            else node->right = NULL;
        }
        return root;
    }
};

TC = O(N), SC = O(N)