//UNION OF TWO SORTED ARRAYS
//Approach 1: using merge procedure (only for sorted arrays):
//Time Complexity: O(m+n) ; Space Complexity: O(1)
/*  
-> Use two index variables i and j, initial values i=0, j=0;
-> If arr1[i]<arr2[j] then print arr[i] and i++
-> If arr1[i]>arr2[j] then print arr2[j] and j++
-> If both are same then print any and both i++ and j++
-> Print remaining elements of the larger array
THIS METHOD DOES NOT ACCOUNT FOR DUPLICATE ELEMENTS: FOR HANDLING DUPLICATES:
CHECK FOR EVERY ELEMENT WHETHER ADJACENT ELEMENTS ARE EQUAL
*/
#include<bits/stdc++.h>
using namespace std;

void printUnion (int arr1[], int arr2[], int m, int n){
    int i=0; int j=0;
    while (i<m && j<n){
        if (arr1[i]<arr2[j]){
            cout<<arr1[i++]<<" ";
        }
        else if(arr2[j]<arr1[i]){
            cout<<arr2[j++]<<" ";
        }
        else{
            cout<<arr2[j++]<<" ";
        }
    }
    while(i<m){
        cout<<arr1[i++]<<" ";
    }
    while(j<n){
        cout<<arr2[j++]<<" ";
    }
}

//--------------------------------------------------
//Approach 2: using set in C++ STL
//Time Complexity:  ;Space Complexity:
#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m){
    set<int> s;
    int i;
    for(i=0; i<n; i++){
        s.insert(a[i]);
    }
    for(i=0; i<m; i++){
        s.insert(b[i]);
    }
return s.size();
}
//---------------------------------------------------
//INTERSECTION OF TWO SORTED ARRAYS
//Approach 1: using merge procedure (only for sorted arrays):
//Time Complexity: O(m+n) ; Space Complexity: O(1)
/*  
-> Use two index variables i and j, initial values i=0, j=0;
-> If arr1[i]<arr2[j] then i++
-> If arr1[i]>arr2[j] then j++
-> If both are same then print any and both i++ and j++
THIS METHOD DOES NOT ACCOUNT FOR DUPLICATE ELEMENTS: FOR HANDLING DUPLICATES:
CHECK FOR EVERY ELEMENT WHETHER ADJACENT ELEMENTS ARE EQUAL
*/
#include<bits/stdc++.h>
using namespace std;

void findIntersection(int arr1[], int arr2[], int m, int n){
    int i = 0, j=0;
    while (i<m && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if (arr2[j]<arr1[i]){
            j++;
        }
        else{
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }
}
