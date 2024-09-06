#include <stdio.h>
#include <stdlib.h>

// Structure for tree
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// Binary Search Tree functions
TreeNode* insert_BST(TreeNode* root, int key);
TreeNode* search_BST(TreeNode* root, int key);
TreeNode* delete_node_BST(TreeNode* root, int key);

// Binary Tree functions
TreeNode* insert(TreeNode* root, int data); // Level order insertion
TreeNode* delete_node(TreeNode* root, int data); // Level order deletion

// Common Tree functions
TreeNode* create_node(int data);
void pre_order_traversal(TreeNode* root);
void in_order_traversal(TreeNode* root);
void post_order_traversal(TreeNode* root);
void free_tree(TreeNode* root);
int get_height(TreeNode* root);
void level_order_traversal(TreeNode* root);
void resize_queue(TreeNode*** queue, int* capacity, int current_size);