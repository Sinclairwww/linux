
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () : val ( 0 ), left ( nullptr ), right ( nullptr ) {}
    TreeNode ( int x ) : val ( x ), left ( nullptr ), right ( nullptr ) {}
    TreeNode ( int x, TreeNode* left, TreeNode* right ) : val ( x ), left ( left ), right ( right ) {}
};


class Solution {
public:
    vector< vector< int > > levelOrder ( TreeNode* root ) {
        vector< vector< int > > ret;
        if ( !root ) {
            return ret;
        }
        // TODO 做一个old queue new queue       赋值    nums不用了
        queue< TreeNode* > nodeQueue;
        queue< int >       numsQueue;
        nodeQueue.push ( root );
        while ( nodeQueue.size () != 0 ) {
            vector< int > level;
            TreeNode*     curr = nodeQueue.front ();
            numsQueue.push ( curr->val );
            if ( curr->left != NULL )
                nodeQueue.push ( curr->left );
            if ( curr->right != NULL )
                nodeQueue.push ( curr->right );
            nodeQueue.pop ();
        }
    }
};