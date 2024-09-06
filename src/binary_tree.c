#include "tree.h"

#define INITIAL_QUEUE_SIZE 10

// Function to insert a node in binary tree in level order
TreeNode* insert_BT(TreeNode* root, int data) {
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
        resize_queue(&queue, &capacity, current_size  + 1);

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

// Function to find the deepest and rightmost node
TreeNode* find_deepest_node(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    int capacity = INITIAL_QUEUE_SIZE;
    int current_size = 0;
    TreeNode** queue = (TreeNode**)malloc(capacity * sizeof(TreeNode*));

    int front = 0, rear = 0;
    queue[rear++] = root;
    current_size++;

    TreeNode* deepest_node = NULL;

    while (front < rear) {
        resize_queue(&queue, &capacity, current_size + 1);

        deepest_node = queue[front++];
        current_size--;

        if (deepest_node->left != NULL) {
            queue[rear++] = deepest_node->left;
            current_size++;
        }
        if (deepest_node->right != NULL) {
            queue[rear++] = deepest_node->right;
            current_size++;
        }
    }

    free(queue);
    return deepest_node;
}

// Function to delete the deepest node
void delete_deepest_node(TreeNode* root, TreeNode* d_node) {
    if (root == NULL) {
        return;
    }

    int capacity = INITIAL_QUEUE_SIZE;
    int current_size = 0;
    TreeNode** queue = (TreeNode**)malloc(capacity * sizeof(TreeNode*));

    int front = 0, rear = 0;
    queue[rear++] = root;
    current_size++;

    while (front < rear) {
        resize_queue(&queue, &capacity, current_size + 1);

        TreeNode* temp = queue[front++];
        current_size--;

        if (temp->left != NULL) {
            if (temp->left == d_node) {
                free(temp->left);
                temp->left = NULL;
                free(queue);
                return;
            } else {
                queue[rear++] = temp->left;
                current_size++;
            }
        }

        if (temp->right != NULL) {
            if (temp->right == d_node) {
                free(temp->right);
                temp->right = NULL;
                free(queue);
                return;
            } else {
                queue[rear++] = temp->right;
                current_size++;
            }
        }
    }

    free(queue);
}

TreeNode* delete_node_BT(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == data) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    int capacity = INITIAL_QUEUE_SIZE;
    int current_size = 0;
    TreeNode** queue = (TreeNode**)malloc(capacity * sizeof(TreeNode*));

    int front = 0, rear = 0;
    queue[rear++] = root;
    current_size++;

    TreeNode* temp = NULL;
    TreeNode* to_delete = NULL;

    while (front < rear) {
        resize_queue(&queue, &capacity, current_size + 1);

        temp = queue[front++];
        current_size--;

        if (temp->data == data) {
            to_delete = temp;
        }

        if (temp->left != NULL) {
            queue[rear++] = temp->left;
            current_size++;
        }

        if (temp->right != NULL) {
            queue[rear++] = temp->right;
            current_size++;
        }
    }

    if (to_delete != NULL) {
        TreeNode* deepest_node = find_deepest_node(root);
        to_delete->data = deepest_node->data;
        delete_deepest_node(root, deepest_node);
    }

    free(queue);
    return root;
}