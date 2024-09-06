#include <stdio.h>
#include <assert.h>
#include "tree.h"

// Function to perform level-order traversal and collect elements into an array
void collect_level_order(TreeNode* root, int* arr, int* size) {
    if (root == NULL) return;

    int capacity = 10;
    TreeNode** queue = (TreeNode**)malloc(capacity * sizeof(TreeNode*));

    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        if (rear >= capacity) {
            capacity *= 2;
            queue = (TreeNode**)realloc(queue, capacity * sizeof(TreeNode*));
            if (!queue) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }

        TreeNode* node = queue[front++];
        arr[(*size)++] = node->data;

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }

    free(queue);
}

// Function to test binary tree insertion
void test_insert_BT() {
    TreeNode* root = NULL;

    root = insert_BT(root, 1);
    root = insert_BT(root, 2);
    root = insert_BT(root, 3);
    root = insert_BT(root, 4);
    root = insert_BT(root, 5);

    // Expected level order traversal
    int expected[] = {1, 2, 3, 4, 5};
    int collected[5];
    int size = 0;

    collect_level_order(root, collected, &size);

    // To check if the elements match the expected level-order
    assert(size == 5);
    for (int i = 0; i < 5; i++) {
        assert(collected[i] == expected[i]);
    }

    printf("Insertion test passed!\n");
}

// Function to test deleting a node in binary tree
void test_delete_node_BT() {
    TreeNode* root = NULL;

    root = insert_BT(root, 1);
    root = insert_BT(root, 2);
    root = insert_BT(root, 3);
    root = insert_BT(root, 4);
    root = insert_BT(root, 5);

    root = delete_node_BT(root, 3);

    // Expected level-order after deletion
    int expected[] = {1, 2, 5, 4};
    int collected[4];
    int size = 0;

    collect_level_order(root, collected, &size);

    // To check if the elements match the expected level-order
    assert(size == 4);
    for (int i = 0; i < 4; i++) {
        assert(collected[i] == expected[i]);
    }

    printf("Delete node test passed!\n");
}

// Main function to run all tests
int main() {
    test_insert_BT();
    test_delete_node_BT();
    
    printf("All tests passed successfully!\n\n");
    
    return 0;
}
