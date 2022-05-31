//Approach 1: binary search and sorting
//time complexity: O(nlogn); space complexity: O(1)
/*The first step is to sort the array in ascending order. Once the array is sorted, traverse the array from left to right, 
and for each element arr[i], binary search for arr[i] + n in arr[i+1..n-1]. If the element is found, return the pair. 
Both first and second steps take O(nLogn). So overall complexity is O(nLogn). 
The second step of the above algorithm can be improved to O(n). The first step remain same. 
The idea for second step is take two index variables i and j, initialize them as 0 and 1 respectively. 
Now run a linear loop. If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j. 
If arr[j] – arr[i] is greater than n, we need to look for greater arr[i], so increment i.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[],int low,int high,int num){
   
   while(high>=low){
       int mid=(low+high)/2;
       
       if(arr[mid]==num)
           return true;
       else if(arr[mid]>num)
           high=mid-1;
       else
           low=mid+1;
   }
   return false;
}


bool findPair(int arr[], int size, int n){
   
   sort(arr,arr+size);
   for(int i=0;i<size;i++){
       
       int d=arr[i]+n;
       if(isPresent(arr,i+1,size-1,d))
           return true;
   }
   
   return false;
}

//------------------------------------------------------
//Approach 2: Hash map
//time complexity: O(n); space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
 
// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
 
        // Check if any element whose frequency
        // is greater than 1 exist or not for n == 0
        if (n == 0 && mpp[arr[i]] > 1)
            return true;
    }
 
    // Check if difference is zero and
    // we are unable to find any duplicate or
    // element whose frequency is greater than 1
    // then no such pair found.
    if (n == 0)
        return false;
 
    for (int i = 0; i < size; i++) {
        if (mpp.find(n + arr[i]) != mpp.end()) {
            cout << "Pair Found: (" << arr[i] << ", "
                 << n + arr[i] << ")";
            return true;
        }
    }
 
    cout << "No Pair found";
    return false;
}
 
