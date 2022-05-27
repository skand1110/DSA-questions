/*
 Power set P(S) of a set S is the set of all subsets of S. If S has n elements in it then P(s) will have 2n elements

Input: Set[], set_size
1. Get the size of power set
      powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
    (a) Loop for i = 0 to set_size
         (i) If ith bit in counter is set
                Print ith element from set for this subset
   (b) Print separator for subsets i.e., newline

*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to print all the power set
void printPowerSet(char* set, int set_size)
{
    // Set_size of power set of a set with set_size
    // n is (2^n-1)
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    // Run from counter 000..0 to 111..1
    for (counter = 0; counter < pow_set_size; counter++) {
        for (j = 0; j < set_size; j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                cout << set[j];
        }
        cout << endl;
    }
}