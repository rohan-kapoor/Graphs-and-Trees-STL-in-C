#include <stdio.h>
#include <stdlib.h>
#include "tree_operations.h"

#define INITIAL_QUEUE_SIZE 10

// Definition for a tree node
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* create_node(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform a pre-order traversal
void pre_order(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

// Function to perform an in-order traversal
void in_order(TreeNode* root) {
    if (root == NULL) return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

// Function to perform a post-order traversal
void post_order(TreeNode* root) {
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

// Function to free the tree
void free_tree(TreeNode* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Function to get the height of tree
int get_height(TreeNode* root){
    if (root == NULL) return 0;
    int left_height = get_height(root -> left);
    int right_height = get_height(root -> right);
    return 1 + ((left_height > right_height) ? (left_height) : (right_height));
}

// Dynamically resizing queue (using for list in printing level order traversal)
void resize_queue(TreeNode*** queue, int* capacity, int current_size){
    if(current_size >= *capacity){
        *capacity *= 2;
        *queue = realloc(*queue, (*capacity) * sizeof(TreeNode*));
    }
    else if(current_size <= (*capacity) / 4 && *capacity > 1){
        *capacity /= 2;
        *queue = realloc(*queue, (*capacity) * sizeof(TreeNode*));
    }
}

// Function to print the level order traversal of tree
void level_order(TreeNode* root){
    if(root == NULL) return;

    int capacity = INITIAL_QUEUE_SIZE;
    int current_size = 0;
    TreeNode** queue = (TreeNode**)malloc(capacity * sizeof(TreeNode*));

    int front = 0, rear = 0;

    queue[rear++] = root;
    current_size++;

    while(front < rear){
        resize_queue(&queue, &capacity, current_size);

        TreeNode* temp = queue[front++];
        current_size--;

        printf("%d ", temp -> data);

        if(temp -> left != NULL){
            queue[rear++] = temp -> right;
            current_size++;
        }
        
        if(temp -> right != NULL){
            queue[rear++] = temp -> right;
            current_size++;
        }
    }
    free(queue);
}