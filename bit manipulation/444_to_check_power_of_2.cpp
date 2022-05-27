//approach:
//if a number n is a power of 2 then bitwise & of n and n-1 will be zero. except for zero. so we will handle that case.
#include <bits/stdc++.h>
using namespace std;
#define bool int
 
/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
 