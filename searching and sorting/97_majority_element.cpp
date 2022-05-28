// Approach 1: sorting
/*
The idea is to sort the array. Sorting makes similar elements in the array adjacent,
so traverse the array and update the count until the present element is similar to the previous one.
If the frequency is more than half the size of the array, print the majority element.
*/
// time complexity: O(nlogn); space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

// Function to find Majority element
// in an array
// it returns -1 if there is no majority element

int majorityElement(int *arr, int n)
{
    if (n == 1)
        return arr[0];

    int cnt = 1;
    // sort the array, o(nlogn)
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            cnt++;
        }
        else
        {
            if (cnt > n / 2)
            {
                return arr[i - 1];
            }
            cnt = 1;
        }
    }
    // if no majority element, return -1
    return -1;
}
//----------------------------------------------------
// Approach 2: hash map
// Time complexity: O(n); space complexity: O(n)
/* C++ program for finding out majority
element in an array */
#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int size)
{
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for (auto i : m)
    {
        if (i.second > size / 2)
        {
            count = 1;
            cout << "Majority found :- " << i.first << endl;
            break;
        }
    }
    if (count == 0)
        cout << "No Majority element" << endl;
}
//--------------------------------------------------
// Approach 3: Using Moore's Voting algorithm
//time complexity: O(n); space complexity: O(1)
/*
This is a two-step process.
-> The first step gives the element that maybe the majority element in the array. If there is a majority element in an array,
then this step will definitely return majority element, otherwise, it will return candidate for majority element.
-> Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.

Algorithm:
-> Loop through each element and maintains a count of majority element, and a majority index, maj_index
-> If the next element is same then increment the count if the next element is not same then decrement the count.
-> if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
-> Now again traverse through the array and find the count of majority element found.
-> If the count is greater than half the size of the array, print the element
-> Else print that there is no majority element
*/

// C++ Program for finding out
// majority element in an array
#include <bits/stdc++.h>
using namespace std;

/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

/* Function to check if the candidate
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

        if (a[i] == cand)
            count++;

    if (count > size / 2)
        return 1;

    else
        return 0;
}

/* Function to print Majority Element */
void printMajority(int a[], int size)
{
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size);

    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand))
        cout << " " << cand << " ";

    else
        cout << "No Majority Element";
}

/* Driver code */
int main()
{
    int a[] = {1, 3, 3, 1, 2};
    int size = (sizeof(a)) / sizeof(a[0]);

    // Function calling
    printMajority(a, size);

    return 0;
}
//------------------------------------------------------