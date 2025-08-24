
class Box{
    public:
    bool bst;
    int sum;
    int max, min;
    Box(){
        bst = 1;
        sum = 0;
        max = INT_MIN;
        min = INT_MAX;
    }
 };

class Solution {
public:
    Box* find(TreeNode* root, int &maxsum){
        //root does not exist
        if(!root){
            return new Box();
        }
        //root exist
        Box* lefthead = find(root->left, maxsum);
        Box* righthead = find(root->right, maxsum);

        if(lefthead->bst && righthead->bst && lefthead->max < root->val && righthead->min > root->val){
            Box* head = new Box();
            head->sum = root->val + lefthead->sum + righthead->sum;
            
            head->min = min(root->val, lefthead->min);
            head->max = max(root->val, righthead->max);
            maxsum = max(head->sum, maxsum);
            return head;
        }
        else{
            Box* head = new Box();
            head->bst = 0;
            return head;
        }
    }
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;
        find(root, maxsum);
        return maxsum;
    }
};