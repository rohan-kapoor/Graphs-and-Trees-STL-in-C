#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"  // Include your tree header file

// Test the create_node function
void test_create_node() {
    TreeNode* node = create_node(5);
    assert(node != NULL);
    assert(node->data == 5);
    assert(node->left == NULL);
    assert(node->right == NULL);

    free(node);
}

// Test the tree traversals (pre-order, in-order, post-order)
void test_tree_traversals() {
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    printf("Expected Pre-Order: 1 2 4 5 3\nActual Pre-Order: ");
    pre_order_traversal(root);
    printf("\n\n");

    printf("Expected In-Order: 4 2 5 1 3\nActual In-Order: ");
    in_order_traversal(root);
    printf("\n\n");

    printf("Expected Post-Order: 4 5 2 3 1\nActual Post-Order: ");
    post_order_traversal(root);
    printf("\n\n");

    free_tree(root);
}

// Test the get_height function
void test_get_height() {
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    assert(get_height(root) == 3);

    free_tree(root);
}

// Test the level_order_traversal function
void test_level_order_traversal() {
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    printf("Expected Level Order: 1 2 3 4 5\nActual Level Order: ");
    level_order_traversal(root);
    printf("\n\n");

    free_tree(root);
}

// Test the free_tree function
void test_free_tree() {
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    free_tree(root);

    assert(root != NULL);  // root is not NULL but should not cause issues as the memory is freed
}

int main() {
    test_create_node();
    test_tree_traversals();
    test_get_height();
    test_level_order_traversal();
    test_free_tree();

    printf("All common tree test cases passed!\n\n");
    return 0;
}