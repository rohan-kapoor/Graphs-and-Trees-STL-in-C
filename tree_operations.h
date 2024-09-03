typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// Function prototypes for common functions
TreeNode* create_node(int data);
void pre_order(TreeNode* root);
void in_order(TreeNode* root);
void post_order(TreeNode* root);
void free_tree(TreeNode* root);
int get_height(TreeNode* root);
void level_order(TreeNode* root);
void resize_queue(TreeNode*** queue, int* capacity, int current_size);