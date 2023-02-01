
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
        queue< TreeNode* > old, neo;
        neo.push ( root );    // initialize

        while ( neo.size () != 0 ) {
            old = neo;
            vector< int > level;
            while ( old.size () != 0 ) {
                TreeNode* curr = old.front ();
                level.push_back ( curr->val );
                if ( curr->left != NULL )
                    neo.push ( curr->left );
                if ( curr->right != NULL )
                    neo.push ( curr->right );
                old.pop ();
            }
            ret.push_back ( level );
        }
        return ret;
    }
};