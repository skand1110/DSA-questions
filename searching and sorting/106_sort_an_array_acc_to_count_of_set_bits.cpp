//Approach 1: using auxiliary array
//time complexity: O(n^2), space complexity: O(n)
/*
Create an auxiliary array and store the set-bit counts of all integers in the aux array
Simultaneously sort both arrays according to the non-increasing order of auxiliary array. (Note that we need to use a stable sort algorithm)
*/
#include <bits/stdc++.h>
using namespace std;
 
// a utility function that returns total set bits count in an integer
int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
 
// Function to simultaneously sort both arrays using insertion sort

void insertionSort(int arr[], int aux[], int n)
{
    for (int i = 1; i < n; i++) {
        // use 2 keys because we need to sort both arrays simultaneously
        int key1 = aux[i];
        int key2 = arr[i];
        int j = i - 1;
 
        // Move elements of arr[0..i-1] and aux[0..i-1],
        // such that elements of aux[0..i-1] are greater
        // than key1, to one position ahead of their current
        // position
        while (j >= 0 && aux[j] < key1) {
            aux[j + 1] = aux[j];
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        aux[j + 1] = key1;
        arr[j + 1] = key2;
    }
}
 
// Function to sort according to bit count using an auxiliary array
void sortBySetBitCount(int arr[], int n)
{
    // Create an array and store count of set bits in it.
    int aux[n];
    for (int i = 0; i < n; i++)
        aux[i] = countBits(arr[i]);
 
    // Sort arr[] according to values in aux[]
    insertionSort(arr, aux, n);
}
 
// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}
//-----------------------------------------------------
//Approach 2: similar method as above but using a stable sorting algorithm instead
/*Using custom comparator of std::sort to sort the array according to set-bit count*/
//time complexity: O(nlogn); space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
 
// a utility function that returns total set bits count in an integer
int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
 
// custom comparator of std::sort
int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
 
    // this takes care of the stability of sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}
 
// Function to sort according to bit count using std::sort
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
}
 
// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}
//-------------------------------------------------
//Approach 3: using counting sort kind of method
//time complexity: O(n), space complexity: O(n)
/* 
There can be a minimum 1 set-bit and only a maximum of 31set-bits in an integer.
Steps (assuming that an integer takes 32 bits):

Create a vector “count” of size 32. Each cell of count i.e., count[i] is another vector that stores all the elements whose set-bit-count is i
Traverse the array and do the following for each element:
Count the number set-bits of this element. Let it be ‘setbitcount’
count[setbitcount].push_back(element)
Traverse ‘count’ in reverse fashion(as we need to sort in non-increasing order) and modify the array.
*/
#include <bits/stdc++.h>
using namespace std;
 
// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1 )
            count+= 1;
        a = a>>1;
    }
    return count;
}
 
// Function to sort according to bit count
// This function assumes that there are 32
// bits in an integer.
void sortBySetBitCount(int arr[],int n)
{
    vector<vector<int> > count(32);
    int setbitcount = 0;
    for (int i=0; i<n; i++)
    {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }
 
    int j = 0;  // Used as an index in final sorted array
 
    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i=31; i>=0; i--)
    {
        vector<int> v1 = count[i];
        for (int i=0; i<v1.size(); i++)
            arr[j++] = v1[i];
    }
}
 
// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}
//----------------------------------------------------------
