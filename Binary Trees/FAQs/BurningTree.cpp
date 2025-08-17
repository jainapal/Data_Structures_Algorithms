class Solution{
	public:
        int burn(TreeNode* root, int& timer, int target){
            //Node doesn't exist
            if(!root) return 0;
            //Node exist
            //Target node
            if(root->data == target){
                return -1;
            }
            int left = burn(root->left, timer, target);
            int right = burn(root->right, timer, target);

            //fire from left
            if(left < 0){
                timer = max(timer, abs(left) + right);
                return left - 1;
            }
            //fire from right
            if(right < 0){
                timer = max(timer, abs(right) + left);
                return right - 1;
            }

            //No fire then return height
            return 1 + max(left, right);
        }
        void find(TreeNode* root, int target, TreeNode* &burnNode){
            if(!root) return;
            if(root->data == target){
                burnNode = root;
                return;
            }
            find(root->left, target, burnNode);
            find(root->right, target, burnNode);
        }
        int height(TreeNode* root){
            if(!root) return 0;
            int left = height(root->left);
            int right = height(root->right);
            return 1 + max(left, right);
        }
		int timeToBurnTree(TreeNode* root, int start){
            int timer = 0;
            burn(root, timer, start);

            //height of target node
            TreeNode* burnNode = NULL;
            find(root, start, burnNode);
            int ht = height(burnNode) - 1;
            return max(timer, ht);
		}	

};
TC = O(N), SC = O(N)
----------------------------------------------------------------------
can also use burn function to find burnNode
int burn(TreeNode* root, int& timer, int target, TreeNode* &burnNode){
            //Node doesn't exist
            if(!root) return 0;
            //Node exist
            //Target node
            if(root->data == target){
                burnNode = root;
                return -1;
            }
            int left = burn(root->left, timer, target, burnNode);
            int right = burn(root->right, timer, target, burnNode);

            //fire from left
            if(left < 0){
                timer = max(timer, abs(left) + right);
                return left - 1;
            }
            //fire from right
            if(right < 0){
                timer = max(timer, abs(right) + left);
                return right - 1;
            }

            //No fire then return height
            return 1 + max(left, right);
        }
        
        int height(TreeNode* root){
            if(!root) return 0;
            int left = height(root->left);
            int right = height(root->right);
            return 1 + max(left, right);
        }
		int timeToBurnTree(TreeNode* root, int start){
            int timer = 0;
            TreeNode* burnNode = NULL;
            burn(root, timer, start, burnNode);

            //height of target node
            int ht = height(burnNode) - 1;
            return max(timer, ht);
		}	