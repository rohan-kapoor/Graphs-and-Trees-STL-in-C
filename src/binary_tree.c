#include "tree.h"

#define INITIAL_QUEUE_SIZE 10

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