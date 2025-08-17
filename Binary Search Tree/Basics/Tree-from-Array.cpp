class Node{
    public:
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
    Node* insert(Node* root, int target){
        if(!root){
            Node* temp = new Node(target);
            return temp;
        }
        if(root->data > target){
            root->left = insert(root->left, target);
        }
        else{
            root->right = insert(root->right, target);
        }
        return root;
    }
    int main(){
        int arr[] = {3,7,4,1,6,8};
        Node* root = nullptr;
        for(int i = 0; i < 6; i++){
            root = insert(root, arr[i]);
        }
    }
};
//TC = O(N^2), SC = O(N)