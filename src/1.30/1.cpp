
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
    void empty ( queue< TreeNode* >& q ) {
        while ( !q.empty () ) {
            q.pop ();
        }
    }

    vector< vector< int > > levelOrder ( TreeNode* root ) {
        vector< vector< int > > ret;
        if ( !root ) {
            return ret;
        }
        queue< TreeNode* > old, neo;
        neo.push ( root );    // initialize

        while ( neo.size () != 0 ) {
            old = neo;
            empty ( neo );
            vector< int > level;
            while ( old.size () != 0 ) {
                auto curr = old.front ();
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

class Solution {
public:
    vector< vector< int > > levelOrder ( TreeNode* root ) {
        vector< vector< int > > ret;
        if ( !root ) {
            return ret;
        }

        queue< TreeNode* > q;
        q.push ( root );
        while ( !q.empty () ) {
            int currentLevelSize = q.size ();
            ret.push_back ( vector< int > () );
            for ( int i = 1; i <= currentLevelSize; ++i ) {
                auto node = q.front ();
                q.pop ();
                ret.back ().push_back ( node->val );
                if ( node->left )
                    q.push ( node->left );
                if ( node->right )
                    q.push ( node->right );
            }
        }

        return ret;
    }
};