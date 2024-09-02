#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"
#include "tree_operations.c"

// Definition for a binary search tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a node in the BST
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum value in a tree (using in deletion of node)
int minimum_value(TreeNode* root){
    if(root == NULL) return 0;
    if(root -> left == NULL) return root -> data;
    minimum_value(root -> left);
}

// Function to delete a node in Binary Search Tree
TreeNode* delete_node(TreeNode* root, int key){
    if(root == NULL) return root;

    if(root -> data == key){
        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
        else if(root -> left == NULL && root -> right != NULL){
            TreeNode* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> left != NULL && root -> right == NULL){
            TreeNode* temp = root -> left;
            free(root);
            return temp;
        }
        else{
            int mini = minimum_value(root -> right);
            root -> data = mini;
            root -> right = delete_node(root -> right, mini);
            return root;
        }
    }
    else if(root -> data < key){
        root -> right = delete_node(root -> right, key);
        return root;
    }
    else{
        root -> left = delete_node(root -> left, key);
        return root;
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    in_order(root);
    printf("\n");

    printf("Pre-order traversal: ");
    pre_order(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order(root);
    printf("\n");

    printf("Searching for 40 in BST: ");
    TreeNode* found = search(root, 40);
    if (found) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Not found\n");
    }

    printf("Deleting 20 from BST\n");
    root = delete_node(root, 20);
    printf("In-order traversal after deletion: ");
    in_order(root);
    printf("\n");

    printf("Deleting 30 from BST\n");
    root = delete_node(root, 30);
    printf("In-order traversal after deletion: ");
    in_order(root);
    printf("\n");

    printf("Deleting 50 from BST\n");
    root = delete_node(root, 50);
    printf("In-order traversal after deletion: ");
    in_order(root);
    printf("\n");

    free_tree(root);
    return 0;
}