//Approach 1:
//Time Complexity: 
/*
A simple solution is to generate all subsets of size m of arr[0..n-1]. 
For every subset, find the difference between the maximum and minimum elements in it. 
Finally, return the minimum difference.
*/

//----------------------------------------------------------
//Approach 2: 
//Time Complexity: 
/*
An efficient solution is based on the observation that to minimize the difference, 
we must choose consecutive elements from a sorted packet. 
We first sort the array arr[0..n-1], 
then find the subarray of size m with the minimum difference between the last and first elements.
*/

// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;
  
// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;
  
    // Sort the given packets
    sort(arr, arr + n);
  
    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;
  
    // Largest number of chocolates
    int min_diff = INT_MAX;
  
    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.
  
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}