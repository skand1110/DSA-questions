// Approach 1:
// Time Complexity: O(n^2); Space Complexity: O(1)
/*
The idea is to process array from left to right.
While processing, find the first out of place element in the
remaining unprocessed array. An element is out of place if
it is negative and at odd index (0 based index), or it is
positive and at even index (0 based index) .
Once we find an out of place element, we find the
first element after it with opposite sign.
We right rotate the subarray between these two elements
(including these two).
*/
/*  C++ program to rearrange
   positive and negative integers
   in alternate fashion while keeping
   the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;
    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);

                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }

        // if no entry has been flagged out-of-place
        if (outofplace == -1)
        {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                outofplace = index;
            }
        }
    }
}

//---------------------------------------------------
// Approach 2:
// Time Complexity: O(nlogn); Space Complexity: O(1)
/*
-> First, sort the array in non-increasing order.
Then we will count the number of positive and negative integers.
-> Then swap the one negative and one positive number
in the odd positions till we reach our condition.
-> This will rearrange the array elements because
we are sorting the array and accessing the element from left to right according to our need.
*/
#include <bits/stdc++.h>
using namespace std;

// Function which works in the condition
// when number of negative numbers are
// lesser or equal than positive numbers
void fill1(int a[], int neg, int pos)
{
    if (neg % 2 == 1)
    {
        for (int i = 1; i < neg; i += 2)
        {
            int c = a[i];
            int d = a[i + neg];
            int temp = c;
            a[i] = d;
            a[i + neg] = temp;
        }
    }
    else
    {
        for (int i = 1; i <= neg; i += 2)
        {
            int c = a[i];
            int d = a[i + neg - 1];
            int temp = c;
            a[i] = d;
            a[i + neg - 1] = temp;
        }
    }
}

// Function which works in the condition
// when number of negative numbers are
// greater than positive numbers
void fill2(int a[], int neg, int pos)
{
    if (pos % 2 == 1)
    {
        for (int i = 1; i < pos; i += 2)
        {
            int c = a[i];
            int d = a[i + pos];
            int temp = c;
            a[i] = d;
            a[i + pos] = temp;
        }
    }
    else
    {
        for (int i = 1; i <= pos; i += 2)
        {
            int c = a[i];
            int d = a[i + pos - 1];
            int temp = c;
            a[i] = d;
            a[i + pos - 1] = temp;
        }
    }
}

// Reverse the array
void reverse(int a[], int n)
{
    int i, k, t;
    for (i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
}

// Print the array
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

//----------------------------------------------------
// Approach 3:
// Time Complexity: O(n) Space Complexity: O(1)
/*
. The idea is to process the array and shift all 
negative values to the end in O(n) time.
. After all negative values are shifted to the end,
 we can easily rearrange array
in alternating positive & negative items.
. We basically swap next positive element at even position 
from next negative element in this step.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to rearrange positive and negative
// integers in alternate fashion. The below
// solution doesn't maintain original order of
// elements
void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1;

    // shift all negative values to the end
    while (i < j)
    {
        while (i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // i has index of leftmost
    // negative element
    if (i == 0 || i == n)
        return;

    // start with first positive
    // element at index 0

    // Rearrange array in alternating
    // positive &
    // negative items
    int k = 0;
    while (k < n && i < n)
    {
        // swap next positive
        // element at even position
        // from next negative element.
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = {2, 3, -4, -1, 6, -9};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}
//----------------------------------------------------