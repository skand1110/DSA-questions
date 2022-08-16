// Approach 1: Counting the number of 1, 0 and 2 and rewriting the array
// Time Complexity: O(n); Space Complexity: O(1)
void sort012(int a[], int n)
{
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count += 1;
        }
        else if (a[i] == 1)
        {
            count1 += 1;
        }
    }
    count2 = n - count + count1;
    for (int i = 0; i < n; i++)
    {
        if (count != 0)
        {
            count -= 1;
            a[i] = 0;
        }
        else if (count1 != 0)
        {
            count1 -= 1;
            a[i] = 1;
        }
        else if (count2 != 0)
        {
            count2 -= 1;
            a[i] = 2;
        }
    }
}
//--------------------------------------------------------------------
// Approach 2: Using Partition technique such that, Maintain 3 variables low, high and mid
// Related topics: Dutch National Flag problem by dijkstra
// low - all elements before low are 0
// mid - all elements between low and mid are 1
// high - all elements after high are 2
/* Initially low, mid are set at 0 and high is at n-1
-> Now, we iterate mid from 0 to high, and for every element
-> if it is equal to 0, we swap it with element at low, and increement low and mid
-> else if it is equal to 2, we swap it with element at high, and decreement high
-> else we just increement mid (i.e element is equla to 1)
This method ensures partition, as low and high maintain elements according to their values,
and then change their positions, ensuring all elements before low are lower than low_value
and all elements after high are higher than high_value
*/

// C++ program to sort an array
// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi)
    {
        switch (a[mid])
        {

        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    cout << "array after segregation ";

    printArray(arr, n);

    return 0;
}
//--------------------------------------------------------------
// Approach 3: Simple Counting and increasing the counter of 0, 1, 2
// Time Complexity: O(n); Space Complexity: O(1)
/* Algorithm:
-> Keep three counter c0 to count 0s, c1 to count 1s and c2 to count 2s
-> Traverse through the array and increase the count of c0 if the element is 0,
increase the count of c1 if the element is 1 and increase the count of c2 if the element is 2
-> Now again traverse the array and replace first c0 elements with 0,
next c1 elements with 1 and next c2 elements with 2.
*/
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the contents of an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Function to sort the array of 0s, 1s and 2s
void sortArr(int arr[], int n)
{
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // Count the number of 0s, 1s and 2s in the array
    for (i = 0; i < n; i++)
    {
        switch (arr[i])
        {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        }
    }

    // Update the array
    i = 0;

    // Store all the 0s in the beginning
    while (cnt0 > 0)
    {
        arr[i++] = 0;
        cnt0--;
    }

    // Then all the 1s
    while (cnt1 > 0)
    {
        arr[i++] = 1;
        cnt1--;
    }

    // Finally all the 2s
    while (cnt2 > 0)
    {
        arr[i++] = 2;
        cnt2--;
    }

    // Print the sorted array
    printArr(arr, n);
}

// Driver code
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(int);

    sortArr(arr, n);

    return 0;
}
