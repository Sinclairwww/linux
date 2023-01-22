#include <stdio.h>
#include <stdlib.h>

int removeDuplicates ( int* nums, int numsSize ) {
    if ( numsSize == 1 ) {
        return 1;
    }
    int  left, right;
    int* ret = ( int* ) malloc ( sizeof ( int ) * numsSize );
    ret[ 0 ] = nums[ 0 ];
    for ( left = 0, right = 1; right < numsSize; right++ ) {
        if ( nums[ right ] > nums[ left ] ) {
            left++;
            nums[ left ] = nums[ right ];
        }
    }
    return left + 1;
}

int main () {
    const int size = 10;
    int       nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int       res = removeDuplicates ( nums, size );
    printf ( "remain: %d\nresult:", res );
    for ( int i = 0; i < res; i++ ) {
        printf ( " %d", nums[ i ] );
    }
    puts ( "" );
    return 0;
}