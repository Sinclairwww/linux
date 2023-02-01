/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int              val;
    struct TreeNode *left, *right;
};


struct TreeNode* sortedArrayToBST ( int* nums, int numsSize ) {
    if ( numsSize == 0 || nums == NULL ) {
        return NULL;
    }

    int midIndex = numsSize / 2;
    int frontSize = numsSize / 2;
    int behindSize = numsSize / 2;
    if ( numsSize % 2 == 0 ) {
        --behindSize;    // when it's even, choose the bigger one
    }


    struct TreeNode* root = ( struct TreeNode* ) malloc ( sizeof ( struct TreeNode ) );
    root->val = nums[ midIndex ];
    root->left = sortedArrayToBST ( nums, frontSize );
    root->right = sortedArrayToBST ( &nums[ midIndex + 1 ], behindSize );

    return root;
}


int main () {
    int              arr[] = { -10, -3, 0, 5, 9 };
    struct TreeNode* res = sortedArrayToBST ( arr, 5 );
    return 0;
}