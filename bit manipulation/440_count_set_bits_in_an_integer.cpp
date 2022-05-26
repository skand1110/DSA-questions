//Approach 1:
//Loop through all bits in an integer, check if a bit is set and if it is, then increment the set bit count.
//time complexity: theta(n); space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
 
/* Function to get no of set bits in binary
representation of positive integer n */
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
//-------------------------------------------------
//Approach 2: recursion
//time complexity: O(logn); space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
 
// recursive function to count set bits
int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;
 
    else
 
        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}
//---------------------------------------------------