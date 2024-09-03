#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h" // Declarations of functions
#include "tree_operations.h"

#define INITIAL_QUEUE_SIZE 10

// Definition for a binary tree node
// struct TreeNode{
//     int data;
//     TreeNode* left;
//     TreeNode* right;
// };

// typedef struct TreeNode TreeNode;


// Dynamically resizing queue
// void resize_queue(TreeNode*** queue, int* capacity, int current_size){
//     if(current_size >= *capacity){
//         *capacity *= 2;
//         *queue = realloc(*queue, (*capacity) * sizeof(TreeNode*));
//     }
//     else if(current_size <= (*capacity) / 4 && *capacity > 1){
//         *capacity /= 2;
//         *queue = realloc(*queue, (*capacity) * sizeof(TreeNode*));
//     }
// }

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

// int main() {
//     TreeNode* root = NULL;
//     root = insert(root, 1);
//     root = insert(root, 2);
//     root = insert(root, 3);
//     root = insert(root, 4);
//     root = insert(root, 5);
//     root = insert(root, 6);
//     root = insert(root, 7);

//     pre_order(root);
//     printf("\n");

//     in_order(root);
//     printf("\n");

//     post_order(root);
//     printf("\n");

//     int height = get_height(root);
//     printf("%d\n", height);

//     level_order(root);
//     printf("\n");

//     return 0;
// }