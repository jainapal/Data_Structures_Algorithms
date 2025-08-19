Node* func(int post[], int &index, int lower, int upper){
    if(index < 0 || post[index] < lower || post[index] > upper) return NULL;
    Node* root = new Node(post[index--]);
    root->right = func(post,index, root->data, upper);
    root->left = func(post, index, lower, root->data);
    return root;
}
Node *constructTree(int post[], int size) {
    size = size - 1;
    Node* temp = func(post, size, INT_MIN, INT_MAX);
    return temp;
}