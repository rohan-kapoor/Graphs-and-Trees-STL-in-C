#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h" // Declarations of functions

#define INITIAL_QUEUE_SIZE 10

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* create_node(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

// Dynamically resizing queue
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

// Function to insert a node in binary tree in level order
TreeNode* insert(TreeNode* root, int data) {
    if(root == NULL) {
        return create_node(data);
    }

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

        if(temp -> left == NULL){
            temp -> left = create_node(data);
            break;
        }
        else{
            queue[rear++] = temp -> left;
            current_size++;
        }

        if(temp -> right == NULL){
            temp -> right = create_node(data);
            break;
        }
        else{
            queue[rear++] = temp -> right;
            current_size++;
        }
    }
    free(queue);
    return root;
}

// Function to print the level order traversal of binary tree
void print_level_order(TreeNode* root){
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

// Function to perform a pre-order traversal of the tree
void pre_order(TreeNode* root){
    if(root == NULL) return;
    printf("%d ", root -> data);
    pre_order(root -> left);
    pre_order(root -> right);
}

// Function to perform an in-order traversal of the tree
void in_order(TreeNode* root){
    if(root == NULL) return;
    in_order(root -> left);
    printf("%d ", root -> data);
    in_order(root -> right);
}

// Function to perform a post-order traversal of the tree
void post_order(TreeNode* root) {
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

void free_tree(TreeNode* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}