/*We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of board. 
The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, 
say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

We can observe that the problem can be broken down into: Given an array A of non-negative integers and a positive integer k, 
we have to divide A into k of fewer partitions such that the maximum sum of the elements in a partition, overall partitions is minimized.

One approach is using dynamic programming.
Another approach using binary search can be found as well. Refer 'allocate minimum number of pages' problem. Here we'll use the binary search approach.
*/

// CPP program for painter's partition problem
#include <iostream>
#include <climits>
using namespace std;
 
// return the maximum element from the array
int getMax(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
 
// return the sum of the elements in the array
int getSum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}
 
// find minimum required painters for given maxlen
// which is the maximum length a painter can paint
int numberOfPainters(int arr[], int n, int maxLen)
{
    int total = 0, numPainters = 1;
 
    for (int i = 0; i < n; i++) {
        total += arr[i];
 
        if (total > maxLen) {
 
            // for next count
            total = arr[i];
            numPainters++;
        }
    }
 
    return numPainters;
}
 
int partition(int arr[], int n, int k)
{
    int lo = getMax(arr, n);
    int hi = getSum(arr, n);
 
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int requiredPainters = numberOfPainters(arr, n, mid);
 
        // find better optimum in lower half
        // here mid is included because we
        // may not get anything better
        if (requiredPainters <= k)
            hi = mid;
 
        // find better optimum in upper half
        // here mid is excluded because it gives
        // required Painters > k, which is invalid
        else
            lo = mid + 1;
    }
 
    // required
    return lo;
}
 
// driver function
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;
    return 0;
}
