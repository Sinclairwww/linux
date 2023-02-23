#include <iostream>
#include <vector>
using namespace std;

void merge ( vector< int >& nums1, int m, vector< int >& nums2, int n ) {
    if ( n == 0 ) {
        return;
    }
    if ( m == 0 ) {
        nums1.swap ( nums2 );
        return;
    }

    for ( int i = nums1.size () - 1; i != m - 1; i-- ) {
        nums1.pop_back ();
    }

    int i = 0;
    while ( !nums2.empty () ) {
        if ( nums2[ 0 ] <= nums1[ i ] ) {
            nums1.insert ( nums1.begin () + i, nums2[ 0 ] );
            nums2.erase ( nums2.begin () );
        } else {
            if ( i != nums1.size () - 1 )
                i++;    // HINT        Update the pointer in nums1
            else {      // HINT       Insert the entire remain vector
                nums1.insert ( nums1.end (), nums2.begin (), nums2.end () );
                break;
            }
        }
    }
}

int main () {
    vector< int > nums1 = { 1, 2, 3, 0, 0, 0 };
    vector< int > nums2 = { 2, 5, 6 };
    merge ( nums1, 3, nums2, 3 );
    for ( auto i : nums1 ) {
        cout << i << " ";
    }
    return 0;
}