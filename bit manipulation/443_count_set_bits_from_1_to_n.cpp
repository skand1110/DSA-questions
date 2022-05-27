//Approach using bit shift method for time complexity of O(n*k) otherwise you can also run a loop and keep counting
//the set bits with time complexity of O(nlogn)

#include <bits/stdc++.h>
using namespace std;
 
// Function which counts set bits from 0 to n
int countSetBits(int n)
{
    int i = 0;
 
    // ans store sum of set bits from 0 to n 
    int ans = 0;
 
    // while n greater than equal to 2^i
    while ((1 << i) <= n) {
 
        // This k will get flipped after
        // 2^i iterations
        bool k = 0;
 
        // change is iterator from 2^i to 1
        int change = 1 << i;
 
        // This will loop from 0 to n for
        // every bit position
        for (int j = 0; j <= n; j++) {
 
            ans += k;
 
            if (change == 1) {
                k = !k; // When change = 1 flip the bit
                change = 1 << i; // again set change to 2^i
            }
            else {
                change--;
            }
        }
 
        // increment the position
        i++;
    }
 
    return ans;
}
//-----------------------------------------------------------------------
//Approach: this method consider that for every number n, there is a number a which is a power of 2 and a<=n
//time complexity: O(logn)
#include <bits/stdc++.h>
using namespace std;
 
int findLargestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}
 
int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = findLargestPower(n);
    return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
}
 