/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int              val;
    struct TreeNode *left, *right;
};
typedef struct {
    int max, min;
} info;

info getInfo ( struct TreeNode* root ) { info ret; }


void midOrderTraverse ( int* arr, int* iptr, struct TreeNode* root ) {
    if ( root == NULL )
        return;
    else {
        midOrderTraverse ( arr, iptr, root->left );
        arr[ *iptr ] = root->val;
        ( *iptr )++;
        midOrderTraverse ( arr, iptr, root->right );
    }
}


bool isValidBST ( struct TreeNode* root ) {
    int arr[ 10001 ];
    int i = 0;
    midOrderTraverse ( arr, &i, root );
    for ( int j = 0; j < i - 1; j++ ) {
        if ( arr[ j ] >= arr[ j + 1 ] )
            return false;
    }
    return true;
}

struct TreeNode* init () {
    struct TreeNode* ret = ( struct TreeNode* ) malloc ( sizeof ( struct TreeNode ) );
    return ret;
}

int main () {
    struct TreeNode* root = init ();
    root->left = init ();
    root->right = init ();
    root->val = 2;
    root->left->val = 1;
    root->right->val = 3;
    if ( isValidBST ( root ) ) {
        puts ( "YES!" );
    } else {
        puts ( "NO!" );
    }
    return 0;
}