#include "tree.h"

// Function to insert a node into the BST
TreeNode* insert_BST (TreeNode* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->data) {
        root->left = insert_BST(root->left, key);
    } else if (key > root->data) {
        root->right = insert_BST(root->right, key);
    }

    return root;
}

// Function to search for a node in the BST
TreeNode* search_BST(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search_BST(root->left, key);
    } else {
        return search_BST(root->right, key);
    }
}

// Function to find the minimum value in a tree (using in deletion of node)
int minimum_value_BST(TreeNode* root){
    if(root == NULL) return 0;
    if(root -> left == NULL) return root -> data;
    minimum_value_BST(root -> left);
}

// Function to delete a node in Binary Search Tree
TreeNode* delete_node_BST(TreeNode* root, int key){
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
            int mini = minimum_value_BST(root -> right);
            root -> data = mini;
            root -> right = delete_node_BST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data < key){
        root -> right = delete_node_BST(root -> right, key);
        return root;
    }
    else{
        root -> left = delete_node_BST(root -> left, key);
        return root;
    }
}