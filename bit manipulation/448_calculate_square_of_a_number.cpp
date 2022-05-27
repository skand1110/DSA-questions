//Approach 1: since multiplication is not allowed, we can do it the old school way by repeatedly adding n 
//time complexity: O(n)

//Approach 2: use bit manipulation right shift method. 
//time complexity: O(logn)
/*
square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

also,
    If n is even, it can be written as
        n = 2*x 
        n2 = (2*x)2 = 4*x2
    If n is odd, it can be written as 
        n = 2*x + 1
        n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
*/

#include <bits/stdc++.h>
using namespace std;
 
int square(int n)
{
    // Base case
    if (n == 0)
        return 0;
 
    // Handle negative number
    if (n < 0)
        n = -n;
 
    // Get floor(n/2) using right shift
    int x = n >> 1;
 
    // If n is odd
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    else // If n is even
        return (square(x) << 2);
}
 