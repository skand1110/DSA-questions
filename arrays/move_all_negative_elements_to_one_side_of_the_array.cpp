// Approach 1: using partiton process of quick sort
//  Time Complexity: O(n); Space Complexity: O(1)
//  A C++ program to put all negative
//  numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver code
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
//----------------------------------------------------------
// Approach 2: Two Pointer Approach: The idea is to solve this problem with constant space O(1)
// and linear time  O(n) is by using a two-pointer or two-variable approach where we simply take
// two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :
/*
-> Check If the left and right pointer elements are negative then simply increment the left pointer.
-> Otherwise, if the left element is positive and the right element is negative then
simply swap the elements, and simultaneously increment and decrement the left and right pointers.
-> Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
Repeat the above 3 steps until the left pointer ≤ right pointer.
*/
#include <iostream>
using namespace std;

// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,
              int right)
{

    // Loop to iterate over the
    // array from left to the right
    while (left <= right)
    {
        // Condition to check if the left
        // and the right elements are
        // negative
        if (arr[left] < 0 && arr[right] < 0)
            left += 1;

        // Condition to check if the left
        // pointer element is positive and
        // the right pointer element is negative
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }

        // Condition to check if both the
        // elements are positive
        else if (arr[left] > 0 && arr[right] > 0)
            right -= 1;
        else
        {
            left += 1;
            right -= 1;
        }
    }
}

// Function to print the array
void display(int arr[], int right)
{

    // Loop to iterate over the element
    // of the given array
    for (int i = 0; i <= right; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {-12, 11, -13, -5,
                 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) /
                   sizeof(arr[0]);

    // Function Call
    shiftall(arr, 0, arr_size - 1);
    display(arr, arr_size - 1);
    return 0;
}
//-----------------------------------------------------------------
//Approach 3: Using Dutch National Flag Algorithm
//Time Complexity: O(n); SPace Complexity: O(1)
#include <iostream>
using namespace std;
 
// Swap Function.
void swap(int &a,int &b){
  int temp =a;
  a=b;
  b=temp;
}
   
// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}
void displayArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main() {
    // Data
    int arr[] = {1, 2,  -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2,  1};
      int n = sizeof(arr)/sizeof(arr[0]);
      reArrange(arr,n);
    displayArray(arr,n);
    return 0;
}