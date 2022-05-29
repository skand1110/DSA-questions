/*
Approach: 
Time complexity: O(logn); space complexity: O(1)

The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search.
The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element 
for which next element to it is smaller than it.
Using the above statement and binary search pivot can be found.
After the pivot is found out divide the array in two sub-arrays.
Now the individual sub – arrays are sorted so the element can be searched using Binary Search.

Improved Solution: 
Approach: Instead of two or more pass of binary search the result can be found in one pass of binary search. 
The binary search needs to be modified to perform the search. The idea is to create a recursive function 
that takes l and r as range in input and the key.

1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..h]
4) Else (arr[mid+1..h] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[h], recur for arr[mid+1..h].
    b) Else recur for arr[l..mid] 
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        //find the index with lowest value.
        // before element at pivot idx, all will be greater than last element
        int start=0,end=n-1;
        while(start<end){
            int mid=(start+end)>>1;
            if(nums[mid]>nums[end]) start=mid+1;
            else end=mid;
        }
        
        int pivotidx=start;
        start=0,end=n-1;
        while(start<end){
            int mid=(start+end)>>1;
            
            int realmid=(mid+pivotidx)%n;
            if(nums[realmid]<target) start=mid+1;
            else end=mid;
        }
        
        int idx=(start+pivotidx)%n;
        if(nums[idx]==target) return idx;
        return -1;
    }
};

//----------------------------------------------------------------------------------

// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;
 
// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
 
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
           Divide other half  into two subarrays,
           such that we can quickly check if key lies
           in other half */
        return search(arr, mid + 1, h, key);
    }
 
    /* If arr[l..mid] first subarray is not sorted, then
    arr[mid... h] must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
 
    return search(arr, l, mid - 1, key);
}
 
//-------------------------------------------------------