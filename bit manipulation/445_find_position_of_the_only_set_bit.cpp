/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, 
find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. 
Position of set bit ‘1’ should be counted starting with 1 from the LSB side in the binary representation of the number.
*/
//approach: The idea is to one by one right shift the set bit of the given number ‘n’ until ‘n’ becomes 0. 
//Count how many times we shifted to make ‘n’ zero. The final count is the position of the set bit. 
//time complexity: O(log base 2 n); space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to check whether n is power of 2 or not
int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));
}
 
// Returns position of the only set bit in 'n'
int findPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;
 
    unsigned count = 0;
 
    // One by one move the only set bit to right till it reaches end
    while (n)
    {
        n = n >> 1;
 
        // increment count of shifts
        ++count;
    }
 
    return count;
}