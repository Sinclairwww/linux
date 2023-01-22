/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode {
    int              val;
    struct TreeNode *left, *right;
};

bool isValidBST ( struct TreeNode* root ) {
    if ( root == NULL || ( root->left == NULL && root->right == NULL ) ) {
        return true;
    } else if ( root->left == NULL && root->right != NULL ) {
        if ( root->val >= root->right->val )
            return false;
    } else if ( root->right == NULL && root->left != NULL ) {
        if ( root->val <= root->left->val )
            return false;
    } else if ( root->val <= root->left->val || root->val >= root->right->val ) {
        return false;
    }
    return ( isValidBST ( root->left ) && isValidBST ( root->right ) );
}


// TODO Can't ensure the properties of BST between grandparent and grandson