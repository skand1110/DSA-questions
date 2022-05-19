//Approach 1: Simple Traversal
//Time Complexity: O(n^2)
/* A simple method is to pick all elements one by one. 
For every picked element, count its occurrences by traversing the array, if count becomes more than n/k, then print the element.
*/
//-------------------------------------------------------------------

//Approach 2: Sorting and then linear traversal
//Time Complexity: O(nlogn) + O(n) = O(nlogn)
/*Similar to above approach but traversal becomes easier*/
//-------------------------------------------------------------------

//Approach 3: Hashing
//Time Complexity: O(n); Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int findElements(int arr[], int n, int k){
    int x = n/k;
      // unordered_map initialization
    unordered_map<int, int> freq;
 
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
   
      // Traversing the map
    for(auto i : freq)
    {
         
        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x)
        {
             
            // Print the key of whose value
            // is greater than x
            cout << i.first << endl;
        }
    }
}