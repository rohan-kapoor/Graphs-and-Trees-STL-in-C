#ifndef binary_tree.h
#define binary_tree.h

typedef struct TreeNode TreeNode;

TreeNode* create_node(int data);
TreeNode* insert(TreeNode* root, int data);
TreeNode* delete_node(TreeNode* root, int data);
void inorder_traversal(TreeNode* root);
void preorder_traversal(TreeNode* root);
void postorder_traversal(TreeNode* root);
int height(TreeNode* root);
void free_tree(TreeNode* root);

#endif