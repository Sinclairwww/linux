/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
struct TreeNode {
    int          val;
    struct node* left;
    struct node* right;
};
typedef struct TreeNode* Tree;

int getMax ( int a, int b ) { return a > b ? a : b; }

int maxDepth ( struct TreeNode* root ) {
    if ( root == NULL ) {
        return 0;
    } else {
        return 1 + getMax ( maxDepth ( root->left ), maxDepth ( root->right ) );
    }
}