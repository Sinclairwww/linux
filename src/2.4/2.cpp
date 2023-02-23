// The API isBadVersion is defined for you.
#include <iostream>

int  loc = 3;
bool isBadVersion ( int version ) { return version >= loc; }

class Solution {
public:
    int firstBadVersion ( int n ) {
        int begin = 1;
        int end = n;
        int half;
        while ( begin < end ) {
            half = ( begin + end ) / 2;
            if ( isBadVersion ( half ) ) {
                end = half - 1;
            } else {
                begin = half + 1;
            }
        }
        return begin;
    }
};

int firstBadVersion ( int n ) {
    int begin = 1;
    int end = n;
    int half;
    while ( begin < end ) {
        half = ( begin + end ) / 2;
        if ( isBadVersion ( half ) ) {
            end = half;
        } else {
            begin = half + 1;
        }
    }
    return end;
}

int main () { std::cout << firstBadVersion ( 6 ) << std::endl; }