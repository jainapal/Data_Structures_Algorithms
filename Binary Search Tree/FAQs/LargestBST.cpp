class Solution {
  public:
  
  struct Box{
    bool bst ;
    int size ;
    int min, max ;
    
    Box(int data){
        bst = 1;
        size = 1;
        min = data;
        max = data;
    }
  };

  
  Box* find(Node* root, int &totalsize){
    //leaf node
    if(!root->left && !root->right){
        totalsize = max(totalsize, 1);
        return new Box(root->data);
    }
    //only right exist
    else if(!root->left && root->right){
        Box* head = find(root->right, totalsize);
        if(head->bst && head->min > root->data){
            head->size++;
            head->min = root->data;
            totalsize = max(totalsize, head->size);
            return head;
        }
        else{
            head->bst = 0;
            return head;
        }
    }
    //only left side exist
    else if(!root->right && root->left){
        Box* head = find(root->left, totalsize);
        if(head->bst && head->max < root->data){
            head->size++;
            head->max = root->data;
            totalsize = max(totalsize, head->size);
            return head;
        }
        else{
            head->bst = 0;
            return head;
        }
    }
    //both sides exist
    else{
        Box* leftHead = find(root->left, totalsize);
        Box* rightHead = find(root->right, totalsize);
        if(leftHead->bst && rightHead->bst && leftHead->max < root->data && rightHead->min > root->data){
            Box* head = new Box(root->data);
            head->size += leftHead->size + rightHead->size;
            head->min = leftHead->min;
            head->max = rightHead->max;
            totalsize = max(totalsize , head->size);
            return head;
        }
        else{
            leftHead->bst = 0;
            return leftHead;
        }
    }
  }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int totalsize = 0;
        find(root, totalsize);
        return totalsize;
    }
};
-----------------------------------------------------------------------------------------------
class Box{
    public:
    bool bst ;
    int size ;
    int min, max ;
    
    Box(){
        bst = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
  public:
  
    Box* find(Node* root, int &totalsize){
      // root does not exist
      if(!root){
          return new Box();
      }
      // root exist
      Box* lefthead = find(root->left, totalsize);
      Box* righthead = find(root->right, totalsize);
      
      if(lefthead->bst && righthead->bst && lefthead->max < root->data && righthead->min > root->data){
          Box* head = new Box();
          head->size = righthead->size + lefthead->size + 1;
          head->min = min(root->data, lefthead->min);
          head->max = max(root->data, righthead->max);
          totalsize = max(totalsize, head->size);
          return head;
      }
      else{
          lefthead->bst = 0;
          return lefthead;
      }
    }
    
    int largestBst(Node *root) {
        int totalsize = 0;
        find(root, totalsize);
        return totalsize;
    }
};