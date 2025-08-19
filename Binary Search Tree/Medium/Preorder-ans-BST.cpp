Given an array arr[ ] of size N consisting of distinct integers,write a program that 
returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.
//Iterative
int canRepresentBST(int arr[], int N) {
        stack<int> lower;
        stack<int> upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left , right;
        
        for(int i = 0; i < N; i++){
            if(arr[i] < lower.top()) return 0;
            while(arr[i] > upper.top()){
                lower.pop();
                upper.pop();
            }
            //in range
            left = lower.top();
            right = upper.top();
            lower.pop();
            upper.pop();
            //put range for right first as we are using stack
            lower.push(arr[i]);
            upper.push(right);
            //put range for left
            lower.push(left);
            upper.push(arr[i]);
        }
        return 1;
    }
    TC = O(N), SC = O(N)
//RECURSIVE
void BST(int arr[], ind &ind, int lower, int upper, int N){
        if(ind == N || arr[ind] < lower || arr[ind] > upper) return;
        int value = arr[ind++];
        //left
        BST(arr, ind, lower, value, N);
        //right
        BST(arr, ind, value, upper, N);
    }
    int canRepresentBST(int arr[], int N) {
        int ind = 0;
        BST(arr, ind, INT_MIN, INT_MAX, N);
        return ind == N ? 1 : 0;
    }
    TC = O(N), SC = O(N)

