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
void resize_queue(TreeNode*** queue, int* capacity){
    *capacity *= 2;
    *queue = realloc(*queue, (*capacity) * sizeof(TreeNode*));
}

// Function to insert a node in binary tree in level order
TreeNode* insert(TreeNode* root, int data) {
    if(root == NULL) {
        return create_node(data);
    }

    TreeNode* temp;
    TreeNode** queue = (TreeNode**)malloc(100 * sizeof(TreeNode*))
}