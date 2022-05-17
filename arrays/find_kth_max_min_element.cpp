//APPROACH 1: brute force, sort and return the element 
//Time complexity: O(nlogn)
#include <algorithm>
#include <iostream>
using namespace std;
 
// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
    // Sort the given array
    sort(arr, arr + n);
 
    // Return k'th element in the sorted array
    return arr[k - 1];
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}

//------------------------------------------------------------------
//APPROACH 2: using set from C++ STL
//Time Complexity: log(n) for average case and O(n) for worst case
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    set<int> s(arr, arr + n);
    set<int>::iterator itr = s.begin(); 
    advance(itr, k - 1); 
 
    cout << *itr << "\n";
 
    return 0;
}
//------------------------------------------------------------------
//APPROACH 3: using min Heap - heap select, call extractMin() k times
//Time complexity : O(n+klogn)
#include <climits>
#include <iostream>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int* x, int* y);
 
// A class for Min Heap
class MinHeap {
    int* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor
    void MinHeapify(int i); // To minheapify subtree rooted with index i
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
 
    int extractMin(); // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};
 
MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a; // store address of array
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the minimum value.
    int root = harr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;
 
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of n elements: O(n) time
    MinHeap mh(arr, n);
 
    // Do extract min (k-1) times
    for (int i = 0; i < k - 1; i++)
        mh.extractMin();
 
    // Return root
    return mh.getMin();
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}
//------------------------------------------------------------------
//APPROACH 4: Quick Select 
// Time complexity: worst case: O(n^2), O(n) on average
#include <climits>
#include <iostream>
using namespace std;
 
int partition(int arr[], int l, int r);
 
// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1) {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
 
        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos - 1, k);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
}
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
//Similarly, MaxHeap can also be used
//------------------------------------------------------------------

