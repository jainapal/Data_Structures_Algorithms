class Solution {
  public:
    TNode* BuildBST(vector<int>& tree, int start, int end){
        if(start > end) return NULL;
        //int mid = (start + end + 1 )/2;
        int mid = start + (end - start + 1) / 2;
        TNode* root = new TNode(tree[mid]);
        root->left = BuildBST(tree, start, mid - 1);
        root->right = BuildBST(tree, mid + 1, end);
        return root;
    }
    TNode *sortedListToBST(LNode *head) {
        vector<int> tree;
        while(head){
            tree.push_back(head->data);
            head = head->next;
        }
        return BuildBST(tree, 0, tree.size() - 1);
    }
};
TC = O(N),SC = O(N) + O(H)