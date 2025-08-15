Scenario 1: Given Preorder and Postorder Traversal
When provided with just preorder and postorder traversals, 
it is not possible to uniquely reconstruct a binary tree. This is 
because multiple trees can produce the same preorder and postorder sequences, 
leaving room for ambiguity.

Scenario 2: Given Preorder and Inorder Traversal
Preorder traversal starts with the root node and explores 
the left subtree before the right subtree. This traversal 
identifies the root and helps in constructing the tree structure. 
In contrast, inorder traversal processes nodes by visiting the left 
subtree first, followed by the root, and then the right subtree. This approach 
clearly separates the left and right subtrees, enabling a unique reconstruction of the binary tree.

Scenario 3: Postorder and Inorder Traversal Given
Postorder traversal visits nodes in the left subtree, 
then the right subtree, and finally the root node. The 
last element represents the root, while preceding elements identify 
subtrees. Inorder traversal provides a clear division between left and right subtrees. 
This combination allows for the unique construction of the binary tree.

Importance of Inorder Traversal
Inorder traversal is crucial for constructing a unique binary tree. Preorder and postorder 
traversals alone do not provide explicit division between left and right subtrees, leading 
to multiple possible structures for nodes with a single child.

Full Binary Tree Case
For a full binary tree, where every node has either zero or two children, the structure is fixed.
Preorder and postorder traversals provide sufficient information to uniquely reconstruct the tree 
due to the absence of single-child nodes.